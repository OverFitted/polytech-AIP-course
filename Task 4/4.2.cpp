#include <iostream>
using namespace std;

int main() {
    long long N;
    const char c = '*';
    cin >> N;

    if (!cin.good() || !cin || cin.peek() == '.' || cin.peek() == ',') {
        cerr << "ERROR: Invalid input data";
        exit(-1);
    } else if (N < 2) {
        cerr << "ERROR: Side length must be greater than 1";
        exit(-1);
    }

    cout << '*' << endl;

    for (int i = 0; i < N - 2; i++) {
        cout << c << string(i, ' ') << c << endl;
    }

    cout << string(N, '*');
}
