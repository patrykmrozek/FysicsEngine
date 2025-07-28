#ifndef FY_BODY_H
#define FY_BODY_H

#include <stdbool.h>
#include <physics/math/vector2.h>
#include <physics/collision/shape.h>


typedef struct fyBody {
    fyVec2 position;
    fyVec2 velocity;
    fyVec2 force;
    float mass;
    
    fyShape shape;
    bool is_active;
} fyBody;


fyAABB fyBody_GetAABB(fyBody* body);

#endif
