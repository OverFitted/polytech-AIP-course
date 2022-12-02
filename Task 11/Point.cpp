#include "Point.h"
#include "cmath"

Point::Point(float x, float y) {
    x_ = x;
    y_ = y;
}
Point::Point() {
    x_ = 0.;
    y_ = 0.;
}
Point::Point(const Point& ref) {
    x_ = ref.x_;
    y_ = ref.y_;
}
Point::~Point() = default;

void Point::setXY(float x, float y) {
    x_ = x;
    y_ = y;
}
void Point::setX(float x) { x_ = x; }
void Point::setY(float y) { y_ = y; }
float Point::getX() const { return x_; }
float Point::getY() const { return y_; }
void Point::move(float k) {
    x_ += k;
    y_ += k;
}

float Point::getDistance(const Point& point) const {
    return sqrt(pow((point.x_ - x_), 2) + pow((point.y_ - y_), 2));
}
