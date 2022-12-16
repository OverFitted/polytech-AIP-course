#include <iostream>
#include "circle.h"

Circle::Circle(float x1, float y1, float circ_r) {
    pos = point_t(x1, y1);
    r = circ_r;
};
Circle::Circle(point_t xy1, float circ_r) {
    pos = xy1;
    r = circ_r;
};
Circle::~Circle() = default;

void Circle::move(float x, float y) {
    pos.setX(pos.getX() + x);
    pos.setY(pos.getY() + y);
};
void Circle::move(point_t new_pos){
    pos.setXY(new_pos.getX(), new_pos.getY());
};
void Circle::scale(float koef){
    r *= koef;
};
float Circle::getArea() const {
    return 3.14 * r * r;
};
rectangle_t Circle::getFrameRect() const {
    return rectangle_t(r * 2, r * 2, pos);
};

Circle* Circle::clone() const {
    return new Circle(pos, r);
}

std::string Circle::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, Circle &ref) {
    rectangle_t rect = ref.getFrameRect();
    point_t rect_pos = rect.getPos();
    float x1 = rect_pos.getX() - rect.getWidth() / 2, x2 = rect_pos.getX() + rect.getWidth() / 2, y1 = rect_pos.getY() - rect.getHeight() / 2, y2 = rect_pos.getY() + rect.getHeight() / 2;
    os << ref.getName() << " " << ref.getArea() << " x y, x y are: " << x2 << " " << y2 << " " << x1 << " " << y1 << std::endl;
    return os;
}
