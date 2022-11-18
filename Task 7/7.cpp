#include <fstream>
#include <iostream>
using namespace std;

bool find_dups(char* first_string, char* second_string, int max_string_length);

int main() {
    int max_str_length = 0, second_str_length = 0;
    string line, token, delimiter = " ", input_file_path = "", output_file_path = "";
    ifstream infile;
    ofstream outfile;

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

    getline(infile, line);
    max_str_length = stoi(line) + 1;

    char* first_string = new char[max_str_length];
    infile.getline(first_string, max_str_length);

    char* second_string = new char[max_str_length];
    infile.getline(second_string, max_str_length);

    infile.close();

    outfile << find_dups(first_string, second_string, max_str_length);
    outfile.close();
}

bool find_dups(char* first_string, char* second_string, int max_string_length) {
    bool flag = false;

    for (int i = 0; i < max_string_length; i++) {
        for (int j = 0; j < max_string_length; j++) {
            if (first_string[i] == second_string[j] && first_string[i] && second_string[j]) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    return flag;
}
