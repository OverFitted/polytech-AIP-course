#include <iostream>
using namespace std;

// Outputing correct sentence about number of crows
int main() {
    int N;
    cout << "Enter crows count:" << endl;
    cin >> N;

    if (!cin) {
        cout << "ERROR: crows count must be a number, exiting...";
        return -1;
    } else {
        if (N % 100 > 10 && N % 100 < 20)
            cout << "В стае " << N << " ворон";
        else {
            switch (N % 10) {
                case 1:
                    cout << "В стае " << N << " ворона";
                    break;

                case 2:
                case 3:
                case 4:
                    cout << "В стае " << N << " вороны";
                    break;

                default:
                    cout << "В стае " << N << " ворон";
                    break;
            }
        }
    }

    return 0;
}
