#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float first = 0, second = 0, third = 0, cur = 0, x = 0, y = 0, z = 0, eps = 10e-5;
    int idx = 0, count = 0;

    while (true) {
        cout << "Enter new sequence element:" << endl;
        cin >> cur;

        if (!cin.good()) {
            cerr << "ERROR: all inputs must be numbers";
            exit(-1);
        }

        if (cur == 0) {
            cout << "Detected 0." << endl;
            cout << "Found " << count << " triples. Sequence ended, exiting...";
            return 0;
        }

        switch (idx) {
            case 0:
                first = cur;
                break;

            case 1:
                second = cur;
                break;

            case 2:
                third = cur;
                break;

            default:
                first = second;
                second = third;
                third = cur;
                break;
        }

        // Not fully sorted. Don't care about first and second. X^2 + Y^2 = Y^2 + X^2
        x = first, y = second, z = third;

        if (x > y) swap(x, y);
        if (y > z) swap(y, z);

        if ((abs(pow(x, 2) + pow(y, 2) - pow(z, 2)) <= eps) && (x * y * z != 0)) {
            cout << "Found new pythagorean triple:" << endl;
            cout << x << " " << y << " " << z << endl;
            count++;
        }

        idx++;
    }
}
