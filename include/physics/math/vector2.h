#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct vec2 {
    float x, y;
} vec2_t;

vec2_t vec2_add(vec2_t v1, vec2_t v2);
vec2_t vec2_subtract(vec2_t v1, vec2_t v2);
vec2_t vec2_scale(vec2_t v, float f);
float vec2_dot(vec2_t v1, vec2_t v2);
float vec2_cross(vec2_t v1, vec2_t v2);

#endif
