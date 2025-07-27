#ifndef FY_WORLD_H
#define FY_WORLD_H

#include <stddef.h>
#include <physics/math/vector2.h>
#include <physics/core/body.h>

typedef struct fyWorld{
    fyBody* bodies; //bodies[x]
    int max_bodies;
    int body_count;
    fyVec2 gravity;;
} fyWorld;


#endif 
