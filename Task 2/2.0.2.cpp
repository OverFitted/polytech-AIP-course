#include <iostream>

int main() {
    float n1 = 123456789,
          n2 = 123456788;
    std::cout << n1 - n2 << '\n';

    int n1_int = 123456789,
        n2_int = 123456788;

    std::cout << n1_int - n2_int << '\n';

    double n1_double = 123456789,
           n2_double = 123456788;

    std::cout << n1_double - n2_double << '\n';

    return 0;
}

// Outputs 8 cuz precision of float is not enough (1.23456789e+8). To fix just change vars type to int, ll, double etc
