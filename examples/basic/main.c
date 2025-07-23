#include <stdio.h>
#include <cglm/cglm.h>
#include <cglm/struct.h>

int main() {
    //testing the vector2 functions
    
    vec2s a = {100, 50};
    vec2s b = {75, 20};
    vec2s c = glms_vec2_add(a, b);
    vec2s d = glms_vec2_sub(a, b);
    vec2s e = glms_vec2_scale(a, 5);

    printf("Addition: %f, %f\n", c.x, c.y);
    printf("Subtraction: %f, %f\n", d.x, d.y);
    printf("Scale: %f, %f", e.x, e.y);



    return 0;
}
