#include <fstream>
#include <iostream>

#include "circle.h"
#include "compositeshape.h"
#include "rectangle.h"
#include "shape.h"

void sort(Shape** arr, int size);
Rectangle* readRect(std::ifstream& file_input);
Circle* readCirc(std::ifstream& file_input);

int main() {
    std::cout << "Enter the input file:\n";
    std::string inputFile;
    std::cin >> inputFile;

    std::ifstream file_input;

    try {
        file_input.open(inputFile);
        if (!file_input) {
            throw std::runtime_error("No such file");
        }
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }

    int count = 0;
    int size = 0;
    std::string name;

    CompositeShape composite;
    std::string type;

    auto** arr = new Shape*[50];

    while (!file_input.eof()) {
        file_input >> type;
        if (type == "COMPLEX") {
            file_input >> size;
            for (int i = 0; i < size; i++) {
                file_input >> name;
                if (name == "RECTANGLE") {
                    Rectangle* shape = readRect(file_input);
                    composite.add(*shape);
                    std::cout << "Entered to composite " << *(shape);
                } else if (name == "CIRCLE") {
                    Circle* shape = readCirc(file_input);
                    composite.add(*shape);
                    std::cout << "Entered to composite " << *(shape);
                } else {
                    file_input.ignore(100, '\n');
                }
            }
            arr[count] = (&composite)->clone();
            count++;
        } else if (type == "RECTANGLE") {
            Rectangle* shape = readRect(file_input);
            arr[count] = shape->clone();
            count++;
            std::cout << "Entered " << *(shape);
        } else if (type == "CIRCLE") {
            Circle* shape = readCirc(file_input);
            arr[count] = shape->clone();
            count++;
            std::cout << "Entered " << *(shape);
        } else {
            file_input.ignore(100, '\n');
        }
    }

    for (int i = 0; i < count; i++)
        (*arr[i]).scale(2);

    for (int i = 0; i < count; i++)
        (*arr[i]).move(1, 1);

    sort(arr, count);

    std::cout << "\nSHAPES AFTER SORT:\n";
    for (int i = 0; i < count; i++) {
        std::cout << *(arr[i]);
    }

    delete[] arr;
    file_input.close();
    return 0;
}

Rectangle* readRect(std::ifstream& file_input) {
    float leftX = 0.0, leftY = 0.0, rightX = 0.0, rightY = 0.0;
    file_input >> leftX >> leftY >> rightX >> rightY;
    auto* rectangle = new Rectangle(leftX, leftY, rightX, rightY);
    return rectangle;
}

Circle* readCirc(std::ifstream& file_input) {
    float X = 0.0, Y = 0.0, R = 0.0;
    file_input >> X >> Y >> R;
    auto* circle = new Circle(X, Y, R);
    return circle;
}

void sort(Shape** arr, int size) {
    Shape* temp;
    bool flag = true;
    while (flag == 1) {
        for (int i = 0; i < size - 1; i++) {
            if (*(arr[i + 1]) < *(arr[i])) {
                temp = &(*arr[i + 1]);
                arr[i + 1] = &(*arr[i]);
                arr[i] = &(*temp);
            }
        }
        flag = false;
    }
}
