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
    body->shape.type = FY_SHAPE_CIRCLE;
    body->shape.data.circle.radius = radius;
}

void fyBody_SetRectangleCollider(fyBody* body, float width, float height) {
    body->shape.type = FY_SHAPE_RECTANGLE;
    body->shape.data.rectangle.width = width;
    body->shape.data.rectangle.height = height;
}

//calls different AABB function depending on the shape
fyAABB fyBody_GetAABB(fyBody* body, fyVec2 position) {
    fyShape* shape = &body->shape;
    switch (shape->type) {
        case FY_SHAPE_CIRCLE:
            return fyAABB_Circle(position, shape->data.circle.radius);
        case FY_SHAPE_RECTANGLE:
            return fyAABB_Rectangle(position, shape->data.rectangle.width,
                                    shape->data.rectangle.height);
    }
}
