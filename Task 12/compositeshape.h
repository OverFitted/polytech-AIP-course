#include "shape.h"

class CompositeShape : public Shape {
   public:
    CompositeShape();
    ~CompositeShape();

    void add(Shape& shape);
    void move(float x, float y) override;
    void move(point_t new_pos) override;
    void scale(float koef) override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    CompositeShape* clone() const override;
    std::string getName() const override;

    friend std::ostream& operator<<(std::ostream& os, CompositeShape& ref);

   private:
    int capacity = 200;
    int currently_added = 0;
    Shape** figures = new Shape*[capacity];
    std::string name = "COMPLEX";
};