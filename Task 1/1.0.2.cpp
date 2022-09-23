#include <iostream>

int main() {
    double inch = 0;
    std::cout << "inches: ";
    std::cin >> inch;
    std::cout << inch << " in = " << inch * 2.54 << " cm\n";
    return 0;
}
