#include "shape.h"
#include <string>

class Rectangle : public Shape {
   public:
    Rectangle(float x1, float y1, float x2, float y2);
    Rectangle(point_t xy1, point_t xy2);
    ~Rectangle();

    void move(float x, float y) override;
    void move(point_t new_pos) override;
    void scale(float koef) override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    Rectangle* clone() const override;
    std::string getName() const override;

    friend std::ostream& operator<<(std::ostream& os, Rectangle& ref);

   private:
    float _x1;
    float _y1;
    float _x2;
    float _y2;
    point_t pos;
    std::string name = "RECTANGLE";
};
