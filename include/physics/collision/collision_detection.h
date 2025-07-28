#ifndef FY_COLLISION_DETECTION_H
#define FY_COLLISION_DETECTION_H

#include <stdbool.h>
#include <physics/math/vector2.h>

typedef struct {
    fyVec2 normal;
    float depth;
    fyVec2 contact_point;
} fyCollision;

#endif
