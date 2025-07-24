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

fyWorld* fy_WorldCreate(const struct fyWorldConfig* config);
void fy_WorldDestroy(fyWorld* world);
void fy_WorldStep(fyWorld* world, float delta_time);
fyBody* fy_WorldCreateBody(fyWorld* world, float mass);
void fy_BodySetPosition(fyBody* body, float x, float y);
fyVec2 fy_BodyGetPosition(fyBody* body);




#endif 
