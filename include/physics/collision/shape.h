#ifndef FY_SHAPE_H
#define FY_SHAPE_H

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_RECTANGLE,
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
