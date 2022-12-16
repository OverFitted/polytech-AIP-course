#include "CompositeShape.h"

#include <iostream>

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

void CompositeShape::move(point_t new_pos) {
    for (int i = 0; i < currently_added; i++)
        (*figures[i]).move(new_pos);
}

float CompositeShape::getArea() const {
    float s = 0;
    for (int i = 0; i < currently_added; i++)
        s += (*figures[i]).getArea();
    return s;
}

void CompositeShape::scale(float koef) {
    for (int i = 0; i < currently_added; i++)
        (*figures[i]).scale(koef);
}

rectangle_t CompositeShape::getFrameRect() const {
    float leftX = 1e10, leftY = 1e10, rightX = -1e10, rightY = -1e10;
    rectangle_t current{};
    rectangle_t frame{};

    for (int i = 0; i < currently_added; i++) {
        current = figures[i][0].getFrameRect();

        float currentLeftX = current.getPos().getX() - current.getWidth() / 2;
        float currentLeftY = current.getPos().getY() - current.getHeight() / 2;
        float currentRightX = current.getPos().getX() + current.getWidth() / 2;
        float currentRightY = current.getPos().getY() + current.getHeight() / 2;

        if (leftX > currentLeftX) {
            leftX = currentLeftX;
        }
        if (leftY > currentLeftY) {
            leftY = currentLeftY;
        }
        if (rightX < currentRightX) {
            rightX = currentRightX;
        }
        if (rightY < currentRightY) {
            rightY = currentRightY;
        }
    }

    frame.setWidth(rightX - leftX);
    frame.setHeight(rightY - leftY);
    frame.getPos().setX(leftX + frame.getWidth() / 2);
    frame.getPos().setY(rightY + frame.getHeight() / 2);

    return frame;
}

std::string CompositeShape::getName() const {
    return name;
}

CompositeShape* CompositeShape::clone() const {
    auto* new_comp = new CompositeShape();

    for (int i = 0; i < currently_added; i++) {
        new_comp->add(*figures[i]);
    }

    return new_comp;
}

std::ostream& operator<<(std::ostream& os, CompositeShape& ref) {
    rectangle_t rect = ref.getFrameRect();
    point_t rect_pos = rect.getPos();
    float x1 = rect_pos.getX() - rect.getWidth() / 2, x2 = rect_pos.getX() + rect.getWidth() / 2, y1 = rect_pos.getY() - rect.getHeight() / 2, y2 = rect_pos.getY() + rect.getHeight() / 2;
    os << ref.getName() << " " << ref.getArea() << "x y, x y are: " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    return os;
}
