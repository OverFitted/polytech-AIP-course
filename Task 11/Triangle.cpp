#include "Triangle.h"
#include <cmath>

Triangle::Triangle(){
    a_ = Point(0., 0.);
    b_ = Point(0., 0.);
    c_ = Point(0., 0.);
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c){
    a_ = a;
    b_ = b;
    c_ = c;
}
Triangle::Triangle(const Triangle& ref){
    a_ = ref.a_;
    b_ = ref.b_;
    c_ = ref.c_;
}
Triangle::~Triangle() = default;

void Triangle::setA(const Point& a) {
    a_ = a;
}
void Triangle::setB(const Point& b) {
    b_ = b;
}
void Triangle::setC(const Point& c) {
    c_ = c;
}
Point Triangle::getA() const {
    return a_;
}
Point Triangle::getB() const {
    return b_;
}
Point Triangle::getC() const {
    return c_;
}
bool Triangle::isTriangle() const {
    return abs(a_.getX() * (b_.getY() - c_.getY()) + b_.getX() * (c_.getY() - a_.getY()) + c_.getX() * (a_.getY() - b_.getY())) >= 0;
}
bool Triangle::isEqual(const Triangle& triangle) const {
    return (a_.getX() == triangle.getA().getX() && a_.getY() == triangle.getA().getY() && b_.getX() == triangle.getB().getX() && b_.getY() == triangle.getB().getY() && c_.getX() == triangle.getC().getX() && c_.getY() == triangle.getC().getY());
}
void Triangle::move(float k) {
    a_.move(k);
    b_.move(k);
    c_.move(k);
}

float Triangle::getPerimeter() const {
    float distAB = a_.getDistance(b_);
    float distAC = a_.getDistance(c_);
    float distBC = b_.getDistance(c_);
    return distAB + distAC + distBC;
}
