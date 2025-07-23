#include "physics/math/vector2.h"

vec2_t vec2_add(vec2_t v1, vec2_t v2) {
    return (vec2_t){v1.x + v2.x, v1.y + v2.y};
}

vec2_t vec2_subtract(vec2_t v1, vec2_t v2) {
    return (vec2_t){v1.x - v2.x, v1.y - v2.y};
}

vec2_t vec2_scale(vec2_t v, float f) {
    return (vec2_t){v.x * f, v.y * f};
}

float vec2_dot(vec2_t v1, vec2_t v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float vec2_cross(vec2_t v1, vec2_t v2) {
    return (v1.x * v2.y) - (v1.y * v2.x);
}


    
