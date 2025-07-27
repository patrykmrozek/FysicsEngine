#include "collision_detection.h"

bool fyAABB_TestOverlap(fyBody* a, fyBody* b) {
    return (a.min.x <= b.max.x && a.max.x >= b.min.x && 
            a.min.y <= b.max.y && a.max.y >= b.min.y);
}

fyAABB fyAABB_Circle(fyVec2 center, float radius) {

}

fyAABB fyAABB_Rectangle(fyVec2 center, float width, float height) {

}

void fyCollision_Resolve(fyBody* a, fyBody* b,  fyCollision* collision) {

}


