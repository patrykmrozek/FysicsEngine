#include <physics/collision/collision_detection.h>

bool fyCollision_CircleVsCircle(fyBody* a, fyBody* b, fyCollisionInfo* output) {
    float dist = fyVec2_DistSquared(a->position, b->position); //dist between centers
    float sum_r = a->shape.data.circle.radius + b->shape.data.circle.radius; //sum radii 
    
    

    return (dist <= sum_r*sum_r);
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
    float closest_x = fyMath_Clamp(circle->position.x, aabb_rect.min.x, aabb_rect.max.x);
    float closest_y = fyMath_Clamp(circle->position.y, aabb_rect.min.y, aabb_rect.max.y);

    float r = circle->shape.data.circle.radius;
    float dist = fyVec2_DistSquared(circle->position, (fyVec2){closest_x, closest_y});

    if (dist <= r*r) {
        return true; //collision
    }
    return false;
}
