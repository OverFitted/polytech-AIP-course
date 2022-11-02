#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

int longest_decr_subseq_length(int arr[], int n, int cur, int prev);

int main() {
    time_t bias = time(nullptr);
    int n, idx = 0;
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

    int array_size = 0, elem = 0;

    try {
        while (myfile.is_open()) {
            if (!getline(myfile, line)) {
                if (idx == 0)
                    throw runtime_error("File is empty");
                break;
            }

            idx++;

            array_size = stoi(line);
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
