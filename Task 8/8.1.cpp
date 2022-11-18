#include <fstream>
#include <iostream>
using namespace std;

ofstream outfile;

void to_file(int value);
int count_ascending_cols(int* arr, int n_rows, int n_cols);
bool is_ascending(int col[], int n);

int main() {
    int a[3][3] = {{1, 2, 3}, {2, 3, 4}, {3, 3, 5}};
    int n = sizeof(a) / sizeof(a[0]);        // число строк
    int m = sizeof(a[0]) / sizeof(a[0][0]);  // число столбцов
    string output_file_path = "";

    try {
        cout << "Enter output file path:" << endl;
        cin >> output_file_path;
        outfile.open(output_file_path);
        if (!outfile) throw runtime_error("Can`t open output file");
    } catch (exception const& file_err) {
        cerr << "ERROR: " << file_err.what() << endl;
        exit(-1);
    }

    to_file(count_ascending_cols(*a, n, m));
}

void to_file(int value) {
    outfile << value;
    outfile.close();
}

bool is_ascending(int col[], int n) {
    if (n == 0 || n == 1)
        return true;

    for (int i = 0; i < n - 1; i++)
        if (col[i] >= col[i + 1])
            return false;

    return true;
}

int count_ascending_cols(int* arr, int n_rows, int n_cols) {
    int count = 0;

    for (int i = 0; i < n_cols; i++) {
        int cur_col[n_rows];
        for (int j = 0; j < n_rows; j++) {
            cur_col[j] = arr[i + j * n_cols];
        }
        count += is_ascending(cur_col, n_rows);
    }

    return count;
}
