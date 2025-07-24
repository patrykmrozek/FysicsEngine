#ifndef FYSICS_H
#define FYSICS_H

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <physics/math/vector2.h>

typedef struct fyWorld fyWorld;
typedef struct fyBody fyBody; 

typedef struct fyWorldConfig {
    int max_bodies;
    int body_count;
    fyVec2 gravity;
} fyWorldConfig;

fyWorld* fy_world_create(const struct fyWorldConfig* config);
void fy_world_destroy(fyWorld* world);
void fy_world_step(fyWorld* world, float delta_time);
fyBody* fy_world_create_body(fyWorld* world, float mass);
void fy_body_set_position(fyBody* body, float x, float y);
fyVec2 fy_body_get_position(fyBody* body);




#endif 
