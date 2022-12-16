#include "CompositeShape.h"

CompositeShape::~CompositeShape() = default;
CompositeShape::CompositeShape() = default;

void CompositeShape::add(Shape& shape) {
    figures[currently_added] = shape.clone();
    currently_added += 1;
}

void CompositeShape::move(float x, float y) {
    for (int i = 0; i < currently_added; i++)
        (*figures[i]).move(x, y);
}