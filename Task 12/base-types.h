#ifndef POLYTECH_AIP_BASE_TYPES_H
#define POLYTECH_AIP_BASE_TYPES_H

class point_t {
   public:
    point_t(float x, float y);
    point_t();
    point_t(const point_t& ref);
    ~point_t();

    void setXY(float x, float y);
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;

   private:
    float x;
    float y;
};

class rectangle_t {
   public:
    rectangle_t(float width, float height, point_t pos);
    rectangle_t(const rectangle_t& ref);
    ~rectangle_t();

    void setHeight(float height);
    void setWidth(float width);
    void setPos(point_t pos);
    float getHeight() const;
    float getWidth() const;
    float getPos() const;

   private:
    float width;
    float height;
    point_t pos;
};


#endif  // POLYTECH_AIP_BASE_TYPES_H
