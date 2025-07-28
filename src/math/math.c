#include <physics/math/math.h>

//clamps value to a min and max
float fyMath_Clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
