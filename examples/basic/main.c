#include <stdio.h>
#include <physics/fysics.h>


int main() {
    
    fyVec2 a = {100, 50};
    fyVec2 b = {75, 20};
    fyVec2 c = vec2_add(a, b);
    fyVec2 d = vec2_sub(a, b);
    fyVec2 e = vec2_scale(a, 5);

    printf("Addition: %f, %f\n", c.x, c.y);
    printf("Subtraction: %f, %f\n", d.x, d.y);
    printf("Scale: %f, %f\n", e.x, e.y);

    // ===========================

    fyWorldConfig config = {5, 0, {0, -9.8f}};
    fyWorld* world = fy_WorldCreate(&config);
    if (!world) {
        printf("Error creating world\n");
    }
    fyBody* body = fy_WorldCreateBody(world, 50.0f);
    if (!body) {
        printf("Error creating body\n");
    }
    
    fyVec2 body_pos = fy_BodyGetPosition(body);
    printf("Initial Body Pos: {%f, %f}\n", body_pos.x, body_pos.y);

    fy_BodySetPosition(body, 100.0f, 100.0f);
    fyVec2 new_body_pos = fy_BodyGetPosition(body);
    printf("New Body Pos: {%f, %f}\n", new_body_pos.x, new_body_pos.y);
    

    // ===========================

    fyBody* body1 = fy_WorldCreateBody(world, 10.0f);
    fyBody* body2 = fy_WorldCreateBody(world, 5.0f);

    fy_BodySetPosition(body1, 100.0f, 100.0f);
    fy_BodySetPosition(body2, 150.0f, 50.0f);

    fyVec2 body1_pos_init = fy_BodyGetPosition(body1);
    fyVec2 body2_pos_init = fy_BodyGetPosition(body2);
    printf("Body 1 Initial Position: {%f, %f}\n", body1_pos_init.x, body1_pos_init.y);
    printf("Body 2 Initial Position: {%f, %f}\n", body2_pos_init.x, body2_pos_init.y);

    //simulating 1 second at 60 fps
    for (int i = 0; i < 60; i++) {
        fy_WorldStep(world, 1.0f / 60.0f);
    }
    //body's x position should remain the same,
    //while the y position should be altered due to gravity
    fyVec2 body1_pos_update = fy_BodyGetPosition(body1);
    fyVec2 body2_pos_update = fy_BodyGetPosition(body2);
    printf("Body 1 Updated Position: {%f, %f}\n", body1_pos_update.x, body1_pos_update.y);
    printf("Body 2 Updated Position: {%f, %f}\n", body2_pos_update.x, body2_pos_update.y);
  

    return 0;
}
