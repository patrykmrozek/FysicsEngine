#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct vec2 {
    float x, y;
} fyVec2;

fyVec2 vec2_add(fyVec2 v1, fyVec2 v2);
fyVec2 vec2_sub(fyVec2 v1, fyVec2 v2);
fyVec2 vec2_scale(fyVec2 v, float f);
float vec2_dot(fyVec2 v1, fyVec2 v2);
float vec2_cross(fyVec2 v1, fyVec2 v2);

#endif
