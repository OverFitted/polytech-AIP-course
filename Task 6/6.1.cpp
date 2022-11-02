// #include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <ctime>
// #include <vector>
using namespace std;

// int binary_search(vector<int> arr, int left, int right, int x);
int longest_decr_subseq_length(int arr[], int n, int cur, int prev);

int main() {
    time_t bias = time(nullptr);
    int n, idx = 0;  //, line_number = 0, line_count = 0, line_length;
    // size_t pos = 0;
    int arr[] = {1, 2, 3, 2, 1, 4, 3, 2, 1};

    cout << "Enter n:" << endl;
    cin >> n;

    try {
        if (!cin.good() || !cin || cin.peek() == '.' || cin.peek() == ',') {
            throw runtime_error("Enter an integer number");
        }

        if (n < 0) {
            throw runtime_error("Enter positive number");
        }
    } catch (exception const& cin_err) {
        cerr << "ERROR: " << cin_err.what() << endl;
        exit(-1);
    }

    int vec[n];
    // vector<int> vec, arr = {1, 2, 3, 2, 1};  // Not dynamic array but vector
    // vector<vector<int>> matrix;  // Vector for file
    // vec.resize(n);
    // generate(vec.begin(), vec.end(), rand);

    cout << "Existing array is:\n";
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        vec[i] = (bias + rand()) % 20;
    }

    cout << "Random array is:\n";
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << "\n" << endl;

    cout << "For existing array: " << longest_decr_subseq_length(arr, n, 0, INT_MAX) << endl;
    cout << "For random array: " << longest_decr_subseq_length(vec, n, 0, INT_MAX) << endl;

    // --- File reading ---

    string line, token, delimiter = " ";
    ifstream myfile;  // to open file
    myfile.open("arrays.txt");

    // line_count = count(istreambuf_iterator<char>(myfile), istreambuf_iterator<char>(), '\n') + 1;
    // matrix.resize(line_count);

    // if (myfile.is_open()) {
    //     while (getline(myfile, line)) {
    //         pos = line.find(delimiter);
    //         token = line.substr(0, pos);
    //         line_length = stoi(token);
    //         matrix[line_number].resize(line_length);
    //         line.erase(0, pos + delimiter.length());
    //         while (idx < line_length) {
    //             token = line.substr(0, pos);
    //             matrix[line_number][idx] = stoi(token);
    //             line.erase(0, pos + delimiter.length());
    //             idx++;
    //         }
    //         idx = 0;
    //         line_number++;
    //     }
    //     myfile.close();
    // }

    int array_size = 0, elem = 0;

    try {
        while (myfile.is_open()) {
            if (!getline(myfile, line)){
                if (idx == 0)
                    throw runtime_error("File is empty");
                break;
            }

            idx++;

            array_size = stoi(line);
            // vector<int> cur_array;
            // cur_array.resize(array_size);
            int cur_array[array_size];

            for (int i = 0; i < array_size; i++) {
                if (!getline(myfile, line)) {
                    throw runtime_error("Not enough input values in file");
                }

                elem = stoi(line);
                cur_array[i] = elem;
            }

            cout << "For file array number " << idx << ": " << longest_decr_subseq_length(cur_array, array_size, 0, INT_MAX) << endl;
        }
    } catch (exception const& file_err) {
        cerr << "ERROR: " << file_err.what() << endl;
        exit(-1);
    }
    myfile.close();
}

// int binary_search(vector<int> arr, int left, int right, int x) {
//     while (right - left > 1) {
//         int m = left + (right - left) / 2;
//         if (arr[m] >= x)
//             right = m;
//         else
//             left = m;
//     }
//     return right;
// }

// int longest_decr_subseq_length(vector<int> arr, int size) {
//     vector<int> table;
//     table.resize(size + 1);

//     for (int i = 0; i < size + 1; i++) {
//         table[i] = i;
//     }

//     table[0] = arr[size - 1];
//     int length = 1;

//     for (int i = size - 1; i > -1; i--) {
//         if (arr[i] < table[0])
//             table[0] = arr[i];
//         else if (arr[i] > table[length - 1]) {
//             table[length] = arr[i];
//             length += 1;
//         } else
//             table[binary_search(table, -1, length - 1, arr[i])] = arr[i];
//     }

//     for (int i = 0; i < sizeof(table); i++) {
//         cout << table[i] << " ";
//     }

//     return length;
// }

int longest_decr_subseq_length(int arr[], int n, int cur, int prev) {
    int include_case = 0, exclude_case = 0;

    if (cur == n) {
        return 0;
    }

    exclude_case = longest_decr_subseq_length(arr, n, cur + 1, prev);

    if (arr[cur] < prev)
        include_case = 1 + longest_decr_subseq_length(arr, n, cur + 1, arr[cur]);

    return max(include_case, exclude_case);
}
