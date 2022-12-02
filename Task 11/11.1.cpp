#include <cmath>
#include <iostream>
#include <vector>

#include "Point.h"
using namespace std;

bool isPointInCircle(const Point& point, float radius);
void input(Point&point), output(const Point&point);

int main() {
    vector<Point> points;
    float min_size = 10e5;
    int min_idx = 0;

    while (true) {
        Point cur_point;
        input(cur_point);

        if (cur_point.getX() == 0. && cur_point.getY() == 0.) {
            break;
        } else {
            points.push_back(cur_point);
        }
    }

    for (int i = 0; i < points.size(); i++) {
        float size = sqrt(pow(points[i].getX(), 2) + pow(points[i].getY(), 2));

        if (size < min_size) {
            min_size = size;
            min_idx = i;
        }
    }

    output(points[min_idx]);
}

bool isPointInCircle(const Point& point, float radius) {
    float size = sqrt(pow(point.getX(), 2) + pow(point.getY(), 2));
    return size <= radius;
}

void input(Point& point) {
    float x, y;

    try {
        cout << "Enter x and y:\n";
        cin >> x >> y;
        if (cin.fail()){
            throw runtime_error("Cords must numbers");
        }
    } catch (exception const& input_err) {
        cerr << "ERROR: " << input_err.what() << endl;
        exit(-1);
    }

    point.setX(x);
    point.setY(y);
}

void output(const Point& point) {
    cout << "x: " << point.getX() << " y: " << point.getY();
}
