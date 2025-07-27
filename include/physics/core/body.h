#ifndef FY_BODY_H
#define FY_BODY_H

#include <stdbool.h>
#include <physics/math/vector2.h>


typedef struct fyBody {
    fyVec2 position;
    fyVec2 velocity;
    fyVec2 force;
    float mass;
    bool is_active;
} fyBody;



#endif
