#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

bool isId(char*left),
    isNumber(char*left),
    isMultiplier(char*left, char*right),
    isTerm(char*left, char*right),
    isExpression(char*left, char*right);
char* findCorBrace(char* left, char* right, int k);
char* findStringEnd(char* num);

int main() {
    int len = 255;
    char* line = new char[len]();

    cout << "Input expression:" << endl;
    cin >> setw(len) >> line;

    char* end = findStringEnd(line);
    cout << isExpression(line, end);

    delete[] line;
}

//<идентификатор> ::= <буква>
bool isId(char* left) {
    if (*left == 'a' || *left == 'b' || *left == 'c' || *left == 'd' || *left == 'e' || *left == 'f' || *left == 'x' || *left == 'y' || *left == 'z') {
        if (*(left + 1) == '+' || *(left + 1) == '*' || *(left + 1) == '-' || *(left + 1) == '/' || *(left + 1) == '\0' || *(left + 1) == ')') {
            return true;
        }
    }
    return false;
}

//<целое без знака> ::= <цифра> | <цифра> <целое без знака>
bool isNumber(char* left) {
    if (*left == '0' || *left == '1' || *left == '2' || *left == '3' || *left == '4' || *left == '5' || *left == '6' || *left == '7' || *left == '8' || *left == '9') {
        if (*(left + 1) == '+' || *(left + 1) == '*' || *(left + 1) == '-' || *(left + 1) == '/' || *(left + 1) == '\0' || *(left + 1) == ')') {
            return true;
        }
        return isNumber(left + 1);
    }
    return false;
}

//<множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
bool isMultiplier(char* left, char* right) {
    if (*left == '(') {
        if (isNumber(left + 1) || isId(left + 1))
            return true;
    }
    if (isNumber(left) || isId(left))
        return true;

    if (*left == '(') {
        char* b_brace = findCorBrace(left + 1, right, 1);
        if (b_brace == nullptr) {
            return false;
        }
        return (isExpression(left + 1, b_brace));
    }
    return false;
}

//<терм> ::= <множитель> | (<множитель> * <терм>) | (<множитель> / <терм>)
bool isTerm(char* left, char* right) {
    if (*left == '(') {
        char* multiplicator = strstr(left, "*");
        char* b_brace = findCorBrace(left + 1, right, 1);
        left++;

        if (b_brace == nullptr)
            return false;

        if (multiplicator != nullptr && multiplicator < b_brace) {
            if (isMultiplier(left + 1, multiplicator) && isTerm(multiplicator + 1, b_brace + 1)) {
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
            if (isMultiplier(left + 1, devisor) && isTerm(devisor + 1, b_brace + 1)) {
                return true;
            }
            return false;
        }
    }

    if (*(left - 1) == '(') left--;
    return isMultiplier(left, right);
}

//<выражение> ::= <терм> | <терм> + <выражение> | <терм> - <выражение>
bool isExpression(char* left, char* right) {
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
        if (isTerm(left, sign)) {
            return isExpression(sign + 1, right);
        }
        return false;
    }
    return isTerm(left, right);
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
