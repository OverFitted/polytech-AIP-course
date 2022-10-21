#include <bits/stdc++.h>

#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool isBinaryPalindrome(int n) {
    string binary = bitset<16>(n).to_string();       // To binary
    binary.erase(0, binary.find_first_not_of('0'));  // Remove leading zeros

    string binary_reverse = binary;                         // Copy binary so I can reverse it and compare 'em
    reverse(binary_reverse.begin(), binary_reverse.end());  // Reverse copied string

    return binary == binary_reverse;
}

int main() {
    int arr[3] = {2, 4, 1}, n, idx = 0, line_count = 0;
    size_t pos = 0;
    vector<int> vec;             // Not dynamic array but vector
    vector<vector<int>> matrix;  // Vector for file

    // cin >> n;

    if (!cin.good() || !cin || cin.peek() == '.' || cin.peek() == ',') {
        cerr << "ERROR: Enter an integer number";
    }

    vec.resize(n);
    generate(vec.begin(), vec.end(), rand);

    // --- File reading ---

    string line, token, delimiter = " ";
    ifstream myfile;  // to open file
    myfile.open("arrays.txt");

    if (myfile.is_open()) {
        line_count++;
        matrix.resize(line_count);

        while (getline(myfile, line)) {
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            matrix[line_count].resize(stoi(token));
            line.erase(0, pos + delimiter.length());

            do {
                token = line.substr(0, pos);
                matrix[line_count][idx] = stoi(token);
                cout << token << " ";
                line.erase(0, pos + delimiter.length());
                idx++;
            } while ((pos = line.find(delimiter)) != string::npos);
            idx = 0;
        }
        myfile.close();
    }

    for (int i = 0; i < line_count; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
            cout << i << " " << j;
        }
        cout << endl;
    }

    // cout << isBinaryPalindrome(n);
}