#ifndef FYCOLLISION_DETECTION_H
#define FYCOLLISION_DETECTION_H

#include <physics/core/body.h>

typedef struct {
    fyVec2 normal;
    float depth;
    fyVec2 contact_point;
} fyCollision;

void fyCollision_Resolve(fyBody* a, fyBody* b,  fyCollision* collision);

#endif
