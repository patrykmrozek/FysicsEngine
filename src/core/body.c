#include <physics/core/body.h>

void fyBody_SetPosition(fyBody* body, float x, float y) {
    body->position = (fyVec2){x, y};
}

fyVec2 fyBody_GetPosition(fyBody* body) {
    return body->position;
}

fyVec2 fyBody_GetVelocity(fyBody* body) {
    return body->velocity;
}

void fyBody_AddForce(fyBody* body, float x, float y) {
    body->force = vec2_add(body->force, (fyVec2){x, y});
}
