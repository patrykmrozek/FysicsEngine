#ifndef FY_WORLD_H
#define FY_WORLD_H

#include <stddef.h>
#include "physics/utils/vector2.h"
#include "physics/core/body.h"

typedef struct fyWorld{
    struct { 
        fyBody* bodies; //objects[x][y]
        int max_bodies;
        int body_count;
    }; 
    fyVec2 gravity;;
} fyWorld;


#endif 
