#include <iostream>
#include "shape.h"

bool Shape::operator<(const Shape &shape) {
    return getArea() < shape.getArea();
}

bool Shape::operator>(const Shape &shape) {
    return getArea() > shape.getArea();
}

std::ostream &operator<<(std::ostream &os, Shape &ref) {
    rectangle_t rect = ref.getFrameRect();
    point_t rect_pos = rect.getPos();
    float x1 = rect_pos.getX() - rect.getWidth() / 2, x2 = rect_pos.getX() + rect.getWidth() / 2, y1 = rect_pos.getY() - rect.getHeight() / 2, y2 = rect_pos.getY() + rect.getHeight() / 2;
    os << ref.getName() << " " << ref.getArea() << " x y, x y are: " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    return os;
}
