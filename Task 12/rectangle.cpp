#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(float x1, float y1, float x2, float y2) {
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
    pos = point_t((x1 + x2) / 2, (y1 + y2) / 2);
};
Rectangle::Rectangle(point_t xy1, point_t xy2) {
    _x1 = xy1.getX();
    _y1 = xy1.getY();
    _x2 = xy2.getX();
    _y2 = xy2.getY();
};
Rectangle::~Rectangle() = default;

void Rectangle::move(float x, float y) {
    _x1 += x;
    _x2 += x;
    _y1 += y;
    _y2 += y;
};
void Rectangle::move(point_t new_pos){
    pos.setXY(new_pos.getX(), new_pos.getY());
};
void Rectangle::scale(float koef){
    _x1 *= koef;
    _x2 *= koef;
    _y1 *= koef;
    _y2 *= koef;
};
float Rectangle::getArea() const {
    return (_x2 - _x1) * (_y2 - _y1);
};
rectangle_t Rectangle::getFrameRect() const {
    return rectangle_t((_x2 - _x1), (_y2 - _y1), pos);
};

Rectangle* Rectangle::clone() const {
    auto* new_rect = new Rectangle(_x1, _y1, _x2, _y2);
    return new_rect;
}

std::string Rectangle::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, Rectangle &ref) {
    rectangle_t rect = ref.getFrameRect();
    point_t rect_pos = rect.getPos();
    float x1 = rect_pos.getX() - rect.getWidth() / 2, x2 = rect_pos.getX() + rect.getWidth() / 2, y1 = rect_pos.getY() - rect.getHeight() / 2, y2 = rect_pos.getY() + rect.getHeight() / 2;
    os << ref.getName() << " " << ref.getArea() << " x y, x y are: " << x2 << " " << y2 << " " << x1 << " " << y1 << std::endl;
    return os;
}
