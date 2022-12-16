#ifndef POLYTECH_AIP_BASE_TYPES_H
#define POLYTECH_AIP_BASE_TYPES_H

class point_t {
   public:
    point_t(float point_x, float point_y);
    point_t();
    point_t(const point_t& ref);
    ~point_t();

    void setXY(float point_x, float point_y);
    void setX(float point_x);
    void setY(float point_y);
    float getX() const;
    float getY() const;

   private:
    float x;
    float y;
};

class rectangle_t {
   public:
    rectangle_t();
    rectangle_t(float rect_width, float rect_height, const point_t& rect_pos);
    rectangle_t(const rectangle_t& ref);
    ~rectangle_t();

    void setHeight(float rect_height);
    void setWidth(float rect_width);
    void setPos(point_t rect_pos);
    float getHeight() const;
    float getWidth() const;
    point_t getPos() const;

   private:
    float width;
    float height;
    point_t pos;
};


#endif  // POLYTECH_AIP_BASE_TYPES_H
