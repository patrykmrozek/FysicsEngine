#include <physics/core/body.h>

void fyBody_SetPosition(fyBody* body, float x, float y) {
    body->position = (fyVec2){x, y};
}

fyVec2 fyBody_GetPosition(fyBody* body) {
    return body->position;
}


