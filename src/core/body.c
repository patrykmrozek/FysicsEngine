#include <physics/core/body.h>

void fy_body_set_position(fyBody* body, float x, float y) {
    body->position = (fyVec2){x, y};
}

fyVec2 fy_body_get_position(fyBody* body) {
    return body->position;
}


