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
    fyVec2 gravity;
} fyWorldConfig;

//fyWorld API
fyWorld* fyWorld_Create(const struct fyWorldConfig* config);
void fyWorld_Destroy(fyWorld* world);
void fyWorld_Step(fyWorld* world, float delta_time);
fyBody* fyWorld_CreateBody(fyWorld* world, float mass);

//fyBody API
void fyBody_SetPosition(fyBody* body, float x, float y);
fyVec2 fyBody_GetPosition(fyBody* body);




#endif 
