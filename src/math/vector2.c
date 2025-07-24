#include <physics/math/vector2.h>

fyVec2 vec2_add(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x + v2.x, v1.y + v2.y};
}

fyVec2 vec2_sub(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x - v2.x, v1.y - v2.y};
}

fyVec2 vec2_scale(fyVec2 v, float f) {
    return (fyVec2){v.x * f, v.y * f};
}

float vec2_dot(fyVec2 v1, fyVec2 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float vec2_cross(fyVec2 v1, fyVec2 v2) {
    return (v1.x * v2.y) - (v1.y * v2.x);
}


