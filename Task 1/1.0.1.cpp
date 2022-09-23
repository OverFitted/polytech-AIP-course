#include <iostream>

const double CM_IN_INCH = 2.54;

double inchToCm(double inch) {
    double res = inch * CM_IN_INCH;
    return res;
}

int main() {
    double inch = 0;
    std::cout << "inches: ";
    std::cin >> inch;
    double cm = inchToCm(inch);
    std::cout << inch << " in = " << cm << " cm\n";
    return 0;
}
