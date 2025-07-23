#ifndef FY_BODY_H
#define FY_BODY_H

#include "physics/utils/vector2.h"


typedef struct Body {
    fyVec2 position;
    fyVec2 velocity;
    fyVec2 force;
    float mass;
} fyBody;



#endif
