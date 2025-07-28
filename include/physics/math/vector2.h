#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

#define EPSILON 0.0001f

typedef struct vec2 {
    float x, y;
} fyVec2;

fyVec2 fyVec2_Add(fyVec2 v1, fyVec2 v2);
fyVec2 fyVec2_Sub(fyVec2 v1, fyVec2 v2);
fyVec2 fyVec2_Scale(fyVec2 v, float f);
float fyVec2_Dot(fyVec2 v1, fyVec2 v2);
float fyVec2_Cross(fyVec2 v1, fyVec2 v2);
float fyVec2_DistSquared(fyVec2 v1, fyVec2 v2);
float fyVec2_Mag(fyVec2 v);
fyVec2 fyVec2_Normal(fyVec2 v);

#endif
