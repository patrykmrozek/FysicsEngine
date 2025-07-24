#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <physics/core/world.h>
#include <physics/core/body.h>
#include <physics/fysics.h>

fyWorld* fy_world_create(const fyWorldConfig* config) {
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
    world->gravity = config->gravity;

    return world;
}

void fy_world_destroy(fyWorld* world) {
    if (!world) return;

    if (world->bodies) {
        free(world->bodies);
    }
    free(world);
    return;
}

fyBody* fy_world_create_body(fyWorld* world, float mass) {
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


void fy_world_step(fyWorld* world, float delta_time) {\
    for (int i = 0; i < world->max_bodies; i++) {
        fyBody* body = &world->bodies[i];
        if (body->is_active) {

            body->velocity.x += world->gravity.x * delta_time;
            body->velocity.y += world->gravity.y * delta_time;

            body->position.x += body->velocity.x * delta_time;
            body->position.y += body->velocity.y * delta_time;
        }
    }
}


