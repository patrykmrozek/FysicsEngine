#ifndef FY_AABB_H
#define FY_AABB_H

#include <stdbool.h>
#include <physics/math/vector2.h>


typedef struct fyAABB {
    fyVec2 min; //bottom left corner
    fyVec2 max; //top right corner
} fyAABB;

//AABB functions
bool fyAABB_TestOverlap(fyAABB a, fyAABB b);
fyAABB fyAABB_Circle(fyVec2 center, float radius);
fyAABB fyAABB_Rectangle(fyVec2 center, float width, float height);


#endif
