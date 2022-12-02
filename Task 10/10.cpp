#include <cmath>
#include <iostream>
using namespace std;

double* eval(int numberMax, float interval[], float interval_step, float absError, double* res);
long long evenFact(int to_num),
    oddFact(int to_num);
double pow(double num, int power);

int main() {
    int numberMax;
    float absError, interval_step, interval[2];

    try {
        cout << "Enter ABS Error:\n";
        cin >> absError;
        if (cin.fail()){
            throw runtime_error("ABS error count must integer");
        }

        if (absError <= 0) {
            throw runtime_error("ABS error count must be positive");
        }
    } catch (exception const& abs_err) {
        cerr << "ERROR: " << abs_err.what() << endl;
        exit(-1);
    }

    try {
        cout << "Enter max numbers count:\n";
        cin >> numberMax;
        if (cin.peek() == '.' || cin.peek() == ',' || cin.fail()){
            throw runtime_error("Max number count must integer");
        }

        if (numberMax <= 0) {
            throw runtime_error("Max number count must be positive");
        }
    } catch (exception const& max_num_err) {
        cerr << "ERROR: " << max_num_err.what() << endl;
        exit(-1);
    }


    try {
        cout << "Enter interval border values:\n";
        cin >> interval[0] >> interval[1];
        if ((interval[0] <= -1) || (interval[1] >= 1)) {
            throw runtime_error("Interval must be in (-1; 1)");
        }
    } catch (exception const& interval_err) {
        cerr << "ERROR: " << interval_err.what() << endl;
        exit(-1);
    }

    try {
        cout << "Enter interval step value:\n";
        cin >> interval_step;
        if (interval_step <= 0) {
            throw runtime_error("Interval step must be positive");
        }
    } catch (exception const& interval_step_err) {
        cerr << "ERROR: " << interval_step_err.what() << endl;
        exit(-1);
    }

    int count_x = (interval[1] - interval[0]) / interval_step;
    double* res = new double[count_x];

    try {
        res = eval(numberMax, interval, interval_step, absError, res);
    } catch (exception const& row_eval_err) {
        cerr << "ERROR: " << row_eval_err.what() << endl;
        exit(-1);
    }

    cout.precision(1);
    cout << "\nexpression: ";
    for (int i = 0; i < count_x; i += 1) {
        cout << " sqrt(" << fixed << 1 + interval[0] + interval_step * i << ")  ";
    }

    cout.precision(9);
    cout << "\nevaluated:  ";
    for (int i = 0; i < count_x; i += 1) {
        cout << fixed << res[i] << " ";
    }

    cout << "\nreal:       ";
    for (int i = 0; i < count_x; i += 1) {
        cout << fixed << sqrt(1 + interval[0] + interval_step * i) << " ";
    }
}

long long evenFact(int to_num) {
    unsigned long long fact_res = 1;
    for (int j = 2; j <= to_num; j += 2)
        fact_res *= j;
    return fact_res;
}

long long oddFact(int to_num) {
    unsigned long long fact_res = 1;
    for (int k = 1; k <= to_num; k += 2)
        fact_res *= k;
    return fact_res;
}

double pow(double num, int power) {
    if (power <= 0) return 1;
    return num * pow(num, --power);
}

// (-1) ^ max(0, i - 1) * odd_fact(2 * min(1, i) - 1) * x^i / even_fact(2 * min(1, i))
double* eval(int numberMax, float interval[], float interval_step, float absError, double* res) {
    int idx = 0;

    for (double x = interval[0]; x < interval[1]; x += interval_step) {
        float real_val = sqrt(1 + x);
        bool reached = false;
        res[idx] = 0.;
        for (int i = 0; i < numberMax; i++) {
            double cur_val = pow(-1, max(0, i - 1)) * ((oddFact(max(1, 2 * (i - 1))) * pow(x, i)) / evenFact(max(1, 2 * i)));
            res[idx] += cur_val;

            if (cur_val / real_val <= absError) {
                reached = true;
                break;
            }
        }

        if (!reached)
            throw runtime_error("Could not reach needed accuracy");

        idx += 1;
    }

    return res;
}

/*
// cout << " res[idx] = " << pow(-1, max(0, i - 1)) * ((oddFact(max(1, 2 * (i - 1))) * pow(x, i)) / evenFact(max(1, 2 * i))) << endl;
// cout << "oddFact(" << max(1, 2 * (i - 1)) << ") = "<< oddFact(max(1, 2 * (i - 1))) << " pow(" << x << ", " << i << ") = " << pow(x, i) << " evenFact(" << max(1, 2 * i) << ") = " << evenFact(max(1, 2 * i));
*/
