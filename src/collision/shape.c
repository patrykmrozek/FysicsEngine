#include <physics/collision/shape.h>

//calls different AABB function depending on the shape
fyAABB fyShape_GetAABB(const fyShape* shape, fyVec2 position) {
    switch (shape->type) {
        case FY_SHAPE_CIRCLE:
            return fyAABB_Circle(position, shape->data.circle.radius);
        case FY_SHAPE_RECTANGLE:
            return fyAABB_Rectangle(position, shape->data.rectangle.width,
                                    shape->data.rectangle.height);
    }
}
