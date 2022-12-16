#ifndef POLYTECH_AIP_SHAPE_H
#define POLYTECH_AIP_SHAPE_H

#include "base-types.h"
#include <string>

class Shape {
   public:
    virtual void move(float x, float y);
    virtual void move(point_t new_pos);
    virtual void scale(float koef);
    virtual float getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual std::string getName() const;
    virtual Shape* clone() const;

    private:
    std::string name;
};

#endif  // POLYTECH_AIP_SHAPE_H
