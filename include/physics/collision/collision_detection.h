#ifndef FY_COLLISION_DETECTION_H
#define FY_COLLISION_DETECTION_H

#include <physics/core/body.h>

typedef struct {
    fyVec2 normal;
    float depth;
    fyVec2 contact_point;
} fyCollision;

typedef struct fyAABB {
    fyVec2 min; //bottom left corner
    fyVec2 max; //top right corner
} fyAABB;

//AABB functions
bool fyAABB_TestOverlap(fyBody* a, fyBody* b);
fyAABB fyAABB_Circle(fyVec2 center, float radius);
fyAABB fyAABB_Rectangle(fyVec2 center, float width, float height);

//collision functions
void fyCollision_Resolve(fyBody* a, fyBody* b,  fyCollision* collision);

#endif
