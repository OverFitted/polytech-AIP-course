#ifndef POLYTECH_AIP_CIRCLE_H
#define POLYTECH_AIP_CIRCLE_H

#include "shape.h"
#include <string>

class Circle : public Shape {
public:
    Circle(float x1, float y1, float circ_r);
    Circle(point_t xy1, float circ_r);
    ~Circle();

    void move(float x, float y) override;
    void move(point_t new_pos) override;
    void scale(float koef) override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    Circle* clone() const override;
    std::string getName() const override;

    friend std::ostream& operator<<(std::ostream& os, Circle& ref);

private:
    float r;
    point_t pos;
    std::string name = "CIRCLE";
};


#endif //POLYTECH_AIP_CIRCLE_H
