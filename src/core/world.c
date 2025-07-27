#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <physics/core/world.h>
#include <physics/core/body.h>
#include <physics/fysics.h>

fyWorld* fyWorld_Create(const fyWorldConfig* config) {
    fyWorld* world = malloc(sizeof(fyWorld));
    if (!world) {
        printf("world creation malloc failed!\n");
        return NULL;
    }
    world->bodies = calloc(config->max_bodies, sizeof(fyBody));
    if (!world->bodies) {
        printf("world bodies calloc failed!\n");
        if (world) {
            free(world);
            return NULL;
        }
    }

    world->max_bodies = config->max_bodies;
    world->body_count = 0;
    world->gravity = (fyVec2){0, 9.8f};

    return world;
}

void fyWorld_Destroy(fyWorld* world) {
    if (!world) return;

    if (world->bodies) {
        free(world->bodies);
    }
    free(world);
    return;
}

fyBody* fyWorld_CreateBody(fyWorld* world, float mass) {
    for (int i = 0; i < world->max_bodies; i++) {
        fyBody* body = &world->bodies[i];
        if (!body[i].is_active) {
            //initialize body
            body->position = (fyVec2){0, 0};
            body->mass = mass;
            body->is_active = true;
            world->body_count ++;
            return body;
        }
    }
    return NULL;
}

void fyWorld_Step(fyWorld* world, float delta_time) {\
    for (int i = 0; i < world->max_bodies; i++) {
        fyBody* body = &world->bodies[i];
        if (body->is_active) {
            //equivalent to force += mass * gravity
            body->force = vec2_add(body->force,
                          vec2_scale(world->gravity, body->mass));
            //printf("FORCE: %f, %f\n", body->force.x, body->force.y);

            //equivalent to velocity += force / (mass * deltaTime)
            body->velocity = vec2_add(body->velocity,
                             vec2_scale(body->force, (body->mass * delta_time)));
            //printf("VELOCITY: %f, %f\n", body->velocity.x, body->velocity.y);
            body->position = vec2_add(body->position,
                                      vec2_scale(body->velocity, delta_time));
            //printf("POSITION: %f, %f\n", body->position.x, body->position.y);
            
            body->force = (fyVec2){0, 0}; //reset net force
        }
    }
}


