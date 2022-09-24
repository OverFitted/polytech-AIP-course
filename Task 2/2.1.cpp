#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Bishops x and y:" << endl;
    cin >> x1 >> y1;

    if (!cin || !cin.good()) {
        cout << "ERROR: input must contain only integer numbers" << endl;
        exit(-1);
    }

    cout << "Piece's x and y:" << endl;
    cin >> x2 >> y2;

    if (!cin || !cin.good()) {
        cout << "ERROR: input must contain only integer numbers" << endl;
        exit(-1);
    }

    if (max(x1, max(y1, max(x2, y2))) > 8) {
        cout << "ERROR: all cords must be less than 8" << endl;
        exit(-1);
    }

    if (min(x1, min(y1, min(x2, y2))) < 1) {
        cout << "ERROR: all cords must be greater than 0" << endl;
        exit(-1);
    }

    if (x1 == x2 and y1 == y2) {
        cout << "ERROR: bishops and piece must be not on the same coordinate" << endl;
        exit(-1);
    }

    if ((abs(x1 - x2) == abs(y1 - y2))) {
        cout << "Beats" << endl;
    } else {
        cout << "Does not beat" << endl;
    }

    return 0;
}
