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

void fyBody_SetCircleCollider(fyBody* body, float radius) {
    body->shape.type = SHAPE_CIRCLE;
    body->shape.data.radius = radius;
}

void fyBody_Set_RectangleCollider(fyBody* body, float width, float height) {
    body->shape.type = SHAPE_RECTANGLE;
    body->shape.data.width = width;
    body->shape.data.height = height;
}
