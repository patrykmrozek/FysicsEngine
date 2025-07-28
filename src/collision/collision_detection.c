#include <physics/collision/collision_detection.h>


bool fyAABB_TestOverlap(fyAABB a, fyAABB b) {
    return (a.min.x <= b.max.x && a.max.x >= b.min.x && 
            a.min.y <= b.max.y && a.max.y >= b.min.y);
}

fyAABB fyAABB_Circle(fyVec2 center, float radius) {
    fyVec2 min = {center.x - radius, center.y - radius};
    fyVec2 max = {center.x + radius, center.y + radius};
    return (fyAABB){min, max};
}

fyAABB fyAABB_Rectangle(fyVec2 center, float width, float height) {
    fyVec2 min = {center.x - width/2, center.y - height/2};
    fyVec2 max = {center.x + width/2, center.y + height/2};
    return (fyAABB){min, max};
}



