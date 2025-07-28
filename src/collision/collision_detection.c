#include <physics/collision/collision_detection.h>

bool fyCollision_CircleVsCircle(fyBody* a, fyBody* b, fyCollisionInfo* output) {
    float dist = fyVec2_Dist(a->position, b->position); //dist between centers
    float sum_r = a->shape.data.circle.radius + b->shape.data.circle.radius; //sum radii 
    return (dist <= sum_r);
}


bool fyCollision_RectVsRect(fyBody* a, fyBody* b, fyCollisionInfo* output) {
    fyAABB aabb_a = fyBody_GetAABB(a);
    fyAABB aabb_b = fyBody_GetAABB(b);
    
    //since I dont have rotations inplemented yet, the AABB check IS the collision check
    if (fyAABB_TestOverlap(aabb_a, aabb_b)) {
        return true;
    }
    return false;
}


bool fyCollision_CircleVsRect(fyBody* circle, fyBody* rect, fyCollisionInfo* info) {
    fyAABB aabb_rect = fyBody_GetAABB(rect);
    //project the circle center onto rectangle, finding nearest point
    float closest_x = clamp(circle->position.x, aabb_rect.min.x, aabb_rect.max.x);
    float closest_y = clamp(circle->position.y, aabb_rect.min.y, aabb_rect.max.y);

    float dist = fyVec2_Dist(circle->position, (fyVec2){closest_x, closest_y});

    if (dist <= circle->shape.data.circle.radius) {
        return true; //collision
    }
    return false;
}
