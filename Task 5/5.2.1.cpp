#include <bits/stdc++.h>

#include <bitset>
#include <iostream>

bool isBinaryPalindrome(int n);

int main() {
    int n;
    std::cout << "Enter integer number:" << std::endl;
    std::cin >> n;

    if (!std::cin.good() || !std::cin || std::cin.peek() == '.' || std::cin.peek() == ',') {
        std::cerr << "ERROR: Invalid input data.";
        exit(-1);
    }

    std::cout << isBinaryPalindrome(n);
}

bool isBinaryPalindrome(int n) {
    std::string binary = std::bitset<16>(n).to_string();  // To binary
    binary.erase(0, binary.find_first_not_of('0'));       // Remove leading zeros

    std::string binary_reverse = binary;                         // Copy binary so I can reverse it and compare em
    std::reverse(binary_reverse.begin(), binary_reverse.end());  // Reverse copied string

    return binary == binary_reverse;
}
