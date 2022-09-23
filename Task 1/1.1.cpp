#include <cmath>
#include <iostream>
using namespace std;

// Calculate roots of square equation with a, b and c coeffs
int main() {
    float a, b, c, roots[2];
    cout << "Enter coefficients a, b and c:" << endl;
    cin >> a >> b >> c;

    if (!cin) {
        cout << "ERROR: Coefficients must be defined as numbers, exiting...";
        exit(-1);
    } else {
        float D = pow(b, 2) - 4. * a * c;

        for (int idx = 0; idx < 2; idx++)
            roots[idx] = (-b + sqrt(D) * pow(-1, idx)) / (2. * a);

        if (D > 0) {
            for (int idx = 0; idx < 2; idx++) {
                cout << "x_" << idx + 1 << " = " << roots[idx] << endl;
            }
        } else if (D == 0)
            cout << "x = " << roots[0];
        else {
            cout << "Not roots found.";
            exit(-1);
        }
    }

    return 0;
}
