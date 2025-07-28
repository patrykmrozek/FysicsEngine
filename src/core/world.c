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
    if (world->body_count >= world->max_bodies) {
        return NULL;
    }

    for (int i = 0; i < world->max_bodies; i++) {
        fyBody* body = &world->bodies[i];
        if (!body->is_active) {
            //initialize body
            body->is_active = true;
            body->position = (fyVec2){0, 0};
            body->velocity = (fyVec2){0, 0};
            body->force = (fyVec2){0, 0};
            body->mass = mass;
            world->body_count ++;
            return body;
        };
    }
    return NULL;
}

void fyWorld_Step(fyWorld* world, float delta_time) {
    for (int i = 0; i < world->max_bodies; i++) {
        //printf("DELTA TIME: %f\n", delta_time);
        fyBody* body = &world->bodies[i];
        if (body->is_active) {
            //f += m * g
            body->force = vec2_add(body->force,
                          vec2_scale(world->gravity, body->mass));

            //a = F/m
            fyVec2 acceleration = vec2_scale(body->force, 1.0f/body->mass);

            //v += a * dt
            body->velocity = vec2_add(body->velocity,
                                      vec2_scale(acceleration, delta_time));

            //x += v * dt
            body->position = vec2_add(body->position,
                                      vec2_scale(body->velocity, delta_time));
            
            body->force = (fyVec2){0, 0}; //reset net force
        }
    }
}


