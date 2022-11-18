#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

bool is_id(char*left),
    is_number(char*left),
    is_multiplier(char*left, char*right),
    is_term(char*left, char*right),
    is_expression(char*left, char*right);
char* findCorBrace(char* left, char* right, int k);
char* findStringEnd(char* num);

int main() {
    int len = 255;
    char* line = new char[len]();

    cout << "Input expression:" << endl;
    cin >> setw(len) >> line;

    char* end = findStringEnd(line);
    cout << is_expression(line, end);

    delete[] line;
}

//<идентификатор> ::= <буква>
bool is_id(char* left) {
    if (*left == 'a' || *left == 'b' || *left == 'c' || *left == 'd' || *left == 'e' || *left == 'f' || *left == 'x' || *left == 'y' || *left == 'z') {
        if (*(left + 1) == '+' || *(left + 1) == '*' || *(left + 1) == '-' || *(left + 1) == '/' || *(left + 1) == '\0' || *(left + 1) == ')') {
            return true;
        }
    }
    return false;
}

//<целое без знака> ::= <цифра> | <цифра> <целое без знака>
bool is_number(char* left) {
    if (*left == '0' || *left == '1' || *left == '2' || *left == '3' || *left == '4' || *left == '5' || *left == '6' || *left == '7' || *left == '8' || *left == '9') {
        if (*(left + 1) == '+' || *(left + 1) == '*' || *(left + 1) == '-' || *(left + 1) == '/' || *(left + 1) == '\0' || *(left + 1) == ')') {
            return true;
        }
        return is_number(left + 1);
    }
    return false;
}

//<множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
bool is_multiplier(char* left, char* right) {
    if (*left == '(') {
        if (is_number(left + 1) || is_id(left + 1))
            return true;
    }
    if (is_number(left) || is_id(left))
        return true;

    if (*left == '(') {
        char* b_brace = findCorBrace(left + 1, right, 1);
        if (b_brace == nullptr) {
            return false;
        }
        return (is_expression(left + 1, b_brace));
    }
    return false;
}

//<терм> ::= <множитель> | (<множитель> * <терм>) | (<множитель> / <терм>)
bool is_term(char* left, char* right) {
    if (*left == '(') {
        char* multiplicator = strstr(left, "*");
        char* b_brace = findCorBrace(left + 1, right, 1);
        left++;

        if (b_brace == nullptr)
            return false;

        if (multiplicator != nullptr && multiplicator < b_brace) {
            if (is_multiplier(left + 1, multiplicator) && is_term(multiplicator + 1, b_brace + 1)) {
                return true;
            }
            return false;
        }
    }

    if (*left == '(') {
        char* devisor = strstr(left, "/");
        char* b_brace = findCorBrace(left + 1, right, 1);
        left++;

        if (b_brace == nullptr)
            return false;

        if (devisor != nullptr && devisor < b_brace) {
            if (is_multiplier(left + 1, devisor) && is_term(devisor + 1, b_brace + 1)) {
                return true;
            }
            return false;
        }
    }

    if (*(left - 1) == '(') left--;
    return is_multiplier(left, right);
}

//<выражение> ::= <терм> | <терм> + <выражение> | <терм> - <выражение>
bool is_expression(char* left, char* right) {
    char *plus, *minus, *sign;

    if (*left == '(') {
        left++;
        char* n_left = findCorBrace(left, right, 1);
        if (n_left == nullptr)
            return false;
        plus = strstr(n_left, "+");
        minus = strstr(n_left, "-");
    } else {
        plus = strstr(left, "+");
        minus = strstr(left, "-");
    }

    if (plus != nullptr && minus != nullptr)
        sign = min(plus, minus);
    else
        sign = max(plus, minus);

    if (sign > strstr(left + 1, "("))
        sign = nullptr;

    if (sign != nullptr && sign < strstr(left, "(")) {
        if (is_term(left, sign)) {
            return is_expression(sign + 1, right);
        }
        return false;
    }
    return is_term(left, right);
}

// find corresponding back brace
char* findCorBrace(char* left, char* right, int k) {
    if (*left == '(')
        k++;
    if (*left == ')')
        k--;
    if (k == 0)
        return left;
    if (left == right)
        return nullptr;
    return findCorBrace(left + 1, right, k);
}

// find end of c-string
char* findStringEnd(char* num) {
    if (*num == '\0')
        return num;
    return findStringEnd(num + 1);
}
