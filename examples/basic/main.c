#include <stdio.h>
#include "physics/utils/vector2.h"


int main() {
    //testing the vector2 functions
    
    fyVec2 a = {100, 50};
    fyVec2 b = {75, 20};
    fyVec2 c = vec2_add(a, b);
    fyVec2 d = vec2_sub(a, b);
    fyVec2 e = vec2_scale(a, 5);

    printf("Addition: %f, %f\n", c.x, c.y);
    printf("Subtraction: %f, %f\n", d.x, d.y);
    printf("Scale: %f, %f", e.x, e.y);



    return 0;
}
