#ifndef POLYTECH_AIP_POINT_H
#define POLYTECH_AIP_POINT_H

#endif //POLYTECH_AIP_POINT_H


class Point {
   public:
    Point(float x, float y);
    Point();
    Point(const Point& ref);
    ~Point();

    void setXY(float x, float y);
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    void move(float k);
    float getDistance(const Point& point) const;

private:
    float x_;
    float y_;
};
