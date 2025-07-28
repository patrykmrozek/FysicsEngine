#include <physics/collision/collision_detection.h>

bool fyCollision_CircleVsCircle(fyBody* a, fyBody* b, fyCollisionInfo* output) {
    float dist = vec2_dist(a->position, b->position); //dist between centers
    float sum_r = a->shape.data.circle.radius + b->shape.data.circle.radius; //sum radii 
    return (dist <= sum_r);
}
