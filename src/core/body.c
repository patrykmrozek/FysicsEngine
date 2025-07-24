#include <physics/core/body.h>

void fy_BodySetPosition(fyBody* body, float x, float y) {
    body->position = (fyVec2){x, y};
}

fyVec2 fy_BodyGetPosition(fyBody* body) {
    return body->position;
}


