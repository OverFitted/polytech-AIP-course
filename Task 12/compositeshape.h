#include "shape.h"

class CompositeShape : public Shape {
   public:
    CompositeShape();
    ~CompositeShape();

    void add(Shape& shape);
    void move(float x, float y);
    void move(point_t new_pos);
    void scale(float koef);
    float getArea() const;
    rectangle_t getFrameRect() const;
    CompositeShape* clone() const;

   private:
    int capacity = 200;
    int currently_added = 0;
    Shape** figures = new Shape*[capacity];
    std::string name = "COMPLEX";
};