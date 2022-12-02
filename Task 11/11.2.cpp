#include <iostream>

#include "Triangle.h"
using namespace std;

bool isEqualSquare(const Triangle& first_triangle, const Triangle& second_triangle);
void output(const Triangle& triangle);

int main(){
    float xa1, ya1, xb1, yb1, xc1, yc1, xa2, ya2, xb2, yb2, xc2, yc2;

    try {
        cout << "Enter Cords of the first triangle:" << endl;
        cin >> xa1 >> ya1 >> xb1 >> yb1 >> xc1 >> yc1;
        if (cin.fail()){
            throw runtime_error("Cords of the first triangle must numbers");
        }
    } catch (exception const& first_err) {
        cerr << "ERROR: " << first_err.what() << endl;
        exit(-1);
    }

    try {
        cout << "Enter Cords of the second triangle:" << endl;
        cin >> xa2 >> ya2 >> xb2 >> yb2 >> xc2 >> yc2;
        if (cin.fail()){
            throw runtime_error("Cords of the second triangle must numbers");
        }
    } catch (exception const& second_err) {
        cerr << "ERROR: " << second_err.what() << endl;
        exit(-1);
    }

    Triangle first_triangle = Triangle(Point(xa1, ya1), Point(xb1, yb1), Point(xc1, yc1));
    Triangle second_triangle = Triangle(Point(xa2, ya2), Point(xb2, yb2), Point(xc2, yc2));

    try {
        if (!first_triangle.isTriangle() || !second_triangle.isTriangle())
            throw runtime_error("Triangles must be valid");
    } catch (exception const& second_err) {
        cerr << "ERROR: " << second_err.what() << endl;
        exit(-1);
    }

    if (first_triangle.isEqual(second_triangle))
        cout << "Triangles are equal.\n";
    else
        cout << "Triangles are not equal.\n";

    if (isEqualSquare(first_triangle, second_triangle))
        cout << "Squares are equal.\n";
    else
       cout << "Squares are not equal.\n";

    if (first_triangle.getPerimeter() == second_triangle.getPerimeter())
        cout << "Perimeters are equal.\n";
    else
        cout << "Perimeters are not equal.\n";

    output(first_triangle);
    cout << endl;
    output(second_triangle);

    float k;

    try {
        cout << "Enter moving distance:\n";
        cin >> k;
        if (cin.fail()){
            throw runtime_error("Moving distance must numbers");
        }
    } catch (exception const& move_err) {
        cerr << "ERROR: " << move_err.what() << endl;
        exit(-1);
    }

    first_triangle.move(k);
    second_triangle.move(k);

    output(first_triangle);
    cout << endl;
    output(second_triangle);
}

bool isEqualSquare(const Triangle& first_triangle, const Triangle& second_triangle){
    float first_square = abs(first_triangle.getA().getX() * (first_triangle.getB().getY() - first_triangle.getC().getY()) + first_triangle.getB().getX() * (first_triangle.getC().getY() - first_triangle.getA().getY()) + first_triangle.getC().getX() * (first_triangle.getA().getY() - first_triangle.getB().getY()));
    float second_square = abs(second_triangle.getA().getX() * (second_triangle.getB().getY() - second_triangle.getC().getY()) + second_triangle.getB().getX() * (second_triangle.getC().getY() - second_triangle.getA().getY()) + second_triangle.getC().getX() * (second_triangle.getA().getY() - second_triangle.getB().getY()));
    return first_square == second_square;
}

void output(const Triangle& triangle) {
    cout << "A is: " << triangle.getA().getX() << " " << triangle.getA().getY() << endl;
    cout << "B is: " << triangle.getB().getX() << " " << triangle.getB().getY() << endl;
    cout << "C is: " << triangle.getC().getX() << " " << triangle.getC().getY() << endl;
}