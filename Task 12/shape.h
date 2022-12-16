#ifndef POLYTECH_AIP_SHAPE_H
#define POLYTECH_AIP_SHAPE_H

#include "base_types.h"
#include <string>

class Shape {
   public:
    virtual void move(float x, float y) = 0;
    virtual void move(point_t new_pos) = 0;
    virtual void scale(float koef) = 0;
    virtual float getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual Shape* clone() const = 0;
    virtual std::string getName() const = 0;

    virtual bool operator>(const Shape& shape);
    virtual bool operator<(const Shape& shape);

    friend std::ostream& operator<<(std::ostream& os, Shape& ref);
};

#endif  // POLYTECH_AIP_SHAPE_H
