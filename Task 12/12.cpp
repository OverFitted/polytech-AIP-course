#include "compositeshape.h"
#include "rectangle.h"
using namespace std;

int main() {
    Rectangle rec[2] = {Rectangle(1, 1, 2, 2), Rectangle(2, 2, 3, 3)};
    CompositeShape comp = CompositeShape();

    for (int i = 0; i < 2; i++){
        comp.add(rec[i]);
    }
}
