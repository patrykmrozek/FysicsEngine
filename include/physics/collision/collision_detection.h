#ifndef FY_COLLISION_DETECTION_H
#define FY_COLLISION_DETECTION_H

#include <stdbool.h>
#include <physics/math/vector2.h>
#include <physics/core/body.h>

typedef struct {
    fyVec2 normal;
    float depth;
    fyVec2 contact_point;
} fyCollisionInfo;

bool fyCollision_CircleVsCircle(fyBody* a, fyBody* b, fyCollisionInfo* output);
bool fyCollision_RectVsRect(fyBody* a, fyBody* b, fyCollisionInfo* output);
bool fyCollision_CircleVsRect(fyBody* circle, fyBody* rect, fyCollisionInfo* info);


#endif
