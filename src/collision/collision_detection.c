#include <physics/collision/collision_detection.h>


bool fyAABB_TestOverlap(fyAABB a, fyAABB b) {
    return (a.min.x <= b.max.x && a.max.x >= b.min.x && 
            a.min.y <= b.max.y && a.max.y >= b.min.y);
}

fyAABB fyAABB_Circle(fyVec2 center, float radius) {
//TODO: implement
}

fyAABB fyAABB_Rectangle(fyVec2 center, float width, float height) {
//TODO: implement
}



