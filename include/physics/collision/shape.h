#ifndef FY_SHAPE_H
#define FY_SHAPE_H

#include <physics/math/vector2.h>
#include <physics/collision/aabb.h>


typedef enum {
    FY_SHAPE_CIRCLE,
    FY_SHAPE_RECTANGLE,
} fyShapeType;

typedef union {
    struct {
        float radius;
    } circle;

    struct {
        float width;
        float height;
    } rectangle;
} fyShapeData;

typedef struct fyShape {
    fyShapeType type;
    fyShapeData data;
} fyShape;


#endif
