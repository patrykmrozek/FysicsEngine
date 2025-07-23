#include <stdio.h>
#include "../../include/physics/math/vector2.h"

int main() {
    //testing the vector2 functions
    
    vec2_t a = {100, 50};
    vec2_t b = {75, 20};
    vec2_t c = vec2_add(a, b);

    printf("Addition: %f, %f\n", c.x, c.y);


    return 0;
}
