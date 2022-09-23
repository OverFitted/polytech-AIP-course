#include <iostream>

int main() {
    double a = 0.1,
           b = 0.2,
           c = 0.3,
           e = 1e-5;

    if (a + b == c)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    if (a + b - c <= e)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}

// Prints out "No" cuz of precision
// To fix just add some rly small epsilon and check using it (lines 14-17)
