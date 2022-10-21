#include <bits/stdc++.h>

#include <bitset>
#include <iostream>
using namespace std;

bool isBinaryPalindrome(int n);

int main() {
    int n;
    cout << "Enter integer number:" << endl;
    cin >> n;

    if (!cin.good() || !cin || cin.peek() == '.' || cin.peek() == ',') {
        cerr << "ERROR: Invalid input data";
        exit(-1);
    }

    cout << isBinaryPalindrome(n);
}

bool isBinaryPalindrome(int n) {
    string binary = bitset<16>(n).to_string();       // To binary
    binary.erase(0, binary.find_first_not_of('0'));  // Remove leading zeros

    string binary_reverse = binary;                         // Copy binary so I can reverse it and compare em
    reverse(binary_reverse.begin(), binary_reverse.end());  // Reverse copied string

    return binary == binary_reverse;
}
