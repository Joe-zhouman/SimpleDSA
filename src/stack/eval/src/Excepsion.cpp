#include "Eval.h"

void UnknownOptrError() {
    std::cout << "!FATAL : unknown operator! " << std::endl;
    exit(-1);
}
bool IsFloatZero(float num) { return fabs(num) <= 1e-10; }

bool IsUnaryOperator(char op) {
    switch (op) {
        case '!':
            return true;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
        case '\0':
            return false;
        default:
            UnknownOptrError();
    }
}