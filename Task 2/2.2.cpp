#include <iostream>
using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;

    if (!cin) {
        cout << "ERROR: input must contain only numbers" << endl;
        exit(-1);
    }

    if (a == b) {
        if (a == c)
            cout << 3 << endl;
        else
            cout << 2 << endl;
    } else if (a == c)
        cout << 2 << endl;
    else if (b == c)
        cout << 2 << endl;
    else
        cout << 1 << endl;

    return 0;
}
