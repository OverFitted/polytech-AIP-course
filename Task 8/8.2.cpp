#include <fstream>
#include <iostream>
using namespace std;

ifstream infile;
ofstream outfile;

int** read_matrix(int n_rows, int n_cols);
void to_file(int value);
int find_min_diag_sum(int** arr, int n_rows, int n_cols);

int main() {
    // Input path to file
    string input_file_path = "", output_file_path = "", line, delimiter = " ";

    try {
        cout << "Enter input file path:" << endl;
        cin >> input_file_path;
        infile.open(input_file_path);
        if (!infile) throw runtime_error("Can`t open input file");

        cout << "Enter output file path:" << endl;
        cin >> output_file_path;
        outfile.open(output_file_path);
        if (!outfile) throw runtime_error("Can`t open output file");
    } catch (exception const& file_err) {
        cerr << "ERROR: " << file_err.what() << endl;
        exit(-1);
    }

    // Read matrix size

    int rows = 1, cols = 1;
    getline(infile, line);
    rows = stoi(line.substr(0, line.find(delimiter)));
    line.erase(0, line.find(delimiter) + delimiter.length());
    cols = stoi(line.substr(0, line.find(delimiter)));

    // Values to matrix

    int** matrix = read_matrix(rows, cols);

    // To file
    to_file(find_min_diag_sum(matrix, rows, cols));
}

int** read_matrix(int n_rows, int n_cols) {
    size_t pos;
    string line, token, delimiter = " ";

    int** matrix = new int*[n_rows];
    for (int i = 0; i < n_rows; i++)
        matrix[i] = new int[n_cols];

    for (int i = 0; i < n_rows; i++) {
        getline(infile, line);
        for (int j = 0; j < n_cols; j++) {
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            try {
                matrix[i][j] = stoi(token);
            } catch (exception const& input_err) {
                cerr << "ERROR: Can't read input file values." << endl;
                exit(-1);
            }
            line.erase(0, pos + delimiter.length());
        }
    }

    infile.close();
    return matrix;
}

void to_file(int value) {
    outfile << value;
    outfile.close();
}

int find_min_diag_sum(int** arr, int n_rows, int n_cols) {
    int n = min(n_cols, n_rows), min_sum = 10e5, s = 0;

    for (int k = 0; k < n; k++) {
        s = 0;
        for (int i = 0; i < n - k; i++) {
            s += arr[i][i + k];
        }
        if (min_sum > s)
            min_sum = s;
    }

    for (int k = 0; k < n; k++) {
        s = 0;
        for (int i = k; i < n; i++) {
            s += arr[i][i - k];
        }
        if (min_sum > s)
            min_sum = s;
    }

    return min_sum;
}
