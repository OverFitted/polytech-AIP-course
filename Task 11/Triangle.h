#ifndef POLYTECH_AIP_TRIANGLE_H
#define POLYTECH_AIP_TRIANGLE_H

#endif //POLYTECH_AIP_TRIANGLE_H

#include "Point.h"

class Triangle {
public:
    Triangle();
    Triangle(const Point& a, const Point& b, const Point& c);
    Triangle(const Triangle& ref);
    ~Triangle();

    void setA(const Point& a);
    void setB(const Point& b);
    void setC(const Point& c);
    Point getA() const;
    Point getB() const;
    Point getC() const;
    bool isTriangle() const;
    bool isEqual(const Triangle& triangle) const;
    void move(float k);
    float getPerimeter() const;

private:
    Point a_;
    Point b_;
    Point c_;
};

