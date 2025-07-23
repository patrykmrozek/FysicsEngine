#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "physics/core/world.h"
#include "physics/core/body.h"
#include "physics/fysics.h"

fyWorld* fy_world_create(const fyWorldConfig* config) {
    fyWorld* world = malloc(sizeof(fyWorld));
    if (!world) {
        printf("world creation malloc failed!\n");
        return NULL;
    }
    world->bodies = calloc(config->max_bodies, sizeof(fyBody));
    if (!world->bodies) {
        printf("world bodies calloc failed!\n");
        if (world) { free(world); }
        return NULL;
    }

    world->max_bodies = config->max_bodies;
    world->body_count = 0;
    world->gravity = config->gravity;

    return world;
}

void fy_world_destroy(fyWorld* world) {

}

void fy_world_add_body(fyBody* body) {

}

void fy_world_remove_body(fyBody* body) {

}

void fy_world_step(fyWorld* world, float delta_time) {

}


