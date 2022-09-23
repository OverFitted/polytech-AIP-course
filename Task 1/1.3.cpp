#include <cmath>
#include <iostream>
using namespace std;

// Output type of triangle given its sides lengths
int main() {
    float a, b, c;
    cout << "Enter the lengths of the sides of the triangle:" << endl;
    cin >> a >> b >> c;

    if (!cin) {
        cout << "ERROR: The lengths of the sides of the triangle must be defined as numbers, exiting...";
        exit(-1);
    } else {
        // sorting a, b and c
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);

        if (pow(c, 2) == pow(a, 2) + pow(b, 2))
            cout << "Rectangular" << endl;
        else if (pow(c, 2) < pow(a, 2) + pow(b, 2))
            cout << "Acute-angled" << endl;
        else if (pow(c, 2) > pow(a, 2) + pow(b, 2))
            cout << "Obtuse-angled" << endl;
        else {
            cout << "Does not exist" << endl;
            exit(-1);
        }
    }

    return 0;
}
