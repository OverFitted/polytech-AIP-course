#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4;

    if (a > c) a += 1;
    d -= 2;
    if (d == 0)
        c = 10;
    else
        c = 11;

    cout << a << " " << b << " " << c << " " << d << endl;
}

/*
a = 1
b = 2
c = 11
d = 2
*/
