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

float fyVec2_Dist(fyVec2 v1, fyVec2 v2) {
    return sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}

