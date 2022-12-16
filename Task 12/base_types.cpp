#include "base_types.h"

point_t::point_t(float point_x, float point_y) {
    x = point_x;
    y = point_y;
}
point_t::point_t() = default;
point_t::point_t(const point_t& ref) {
    x = ref.getX();
    y = ref.getY();
}
point_t::~point_t() = default;

void point_t::setXY(float point_x, float point_y) {
    x = point_x;
    y = point_y;
}
void point_t::setX(float point_x) {
    x = point_x;
}
void point_t::setY(float point_y) {
    y = point_y;
}
float point_t::getX() const {
    return x;
}
float point_t::getY() const {
    return y;
}

rectangle_t::rectangle_t(){
    width = 0;
    height = 0;
    pos = point_t(0, 0);
}

rectangle_t::rectangle_t(float rect_width, float rect_height, const point_t& rect_pos){
    width = rect_width;
    height = rect_height;
    pos = rect_pos;
}

rectangle_t::rectangle_t(const rectangle_t& ref) {
    width = ref.width;
    height = ref.height;
    pos = ref.pos;
}

void rectangle_t::setHeight(float rect_height) {
    height = rect_height;
}

void rectangle_t::setWidth(float rect_width) {
    width = rect_width;
}

void rectangle_t::setPos(point_t rect_pos) {
    pos = rect_pos;
}

float rectangle_t::getHeight() const {
    return height;
}

float rectangle_t::getWidth() const {
    return width;
}

point_t rectangle_t::getPos() const {
    return pos;
}

rectangle_t::~rectangle_t() = default;
