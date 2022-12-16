#include "shape.h"

class Rectangle : public Shape {
   public:
    Rectangle(float x1, float y1, float x2, float y2);
    Rectangle(point_t xy1, point_t xy2);
    ~Rectangle();

    void move(float x, float y);
    void move(point_t new_pos);
    void scale(float koef);
    float getArea() const;
    rectangle_t getFrameRect() const;
    Rectangle* clone() const;

   private:
    float _x1;
    float _y1;
    float _x2;
    float _y2;
    point_t pos;
    std::string name = "RECTANGLE";
};
