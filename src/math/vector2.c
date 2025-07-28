#include <physics/math/vector2.h>

fyVec2 fyVec2_Add(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x + v2.x, v1.y + v2.y};
}

fyVec2 fyVec2_Sub(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x - v2.x, v1.y - v2.y};
}

fyVec2 fyVec2_Mul(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x * v2.x, v1.y * v2.y};
}

fyVec2 fyVec2_Div(fyVec2 v1, fyVec2 v2) {
    return (fyVec2){v1.x / v2.x, v1.y / v2.y};
} 

fyVec2 fyVec2_Scale(fyVec2 v, float f) {
    return (fyVec2){v.x * f, v.y * f};
}

float fyVec2_Dot(fyVec2 v1, fyVec2 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

float fyVec2_Cross(fyVec2 v1, fyVec2 v2) {
    return (v1.x * v2.y) - (v1.y * v2.x);
}

float fyVec2_DistSquared(fyVec2 v1, fyVec2 v2) {
    // (v1x-v2x)^2 + (v1y-v2y)^2 - avoiding slow sqrt()
    float dx = v1.x - v2.x;
    float dy = v1.y - v2.y;
    return dx * dx + dy * dy;
}

float fyVec2_Mag(fyVec2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

fyVec2 fyVec2_Normal(fyVec2 v) {
    float mag = fyVec2_Mag(v);
    if (mag < EPSILON) return (fyVec2){0.0f, 0.0f};
    return fyVec2_Scale(v, 1.0f/mag);
}

