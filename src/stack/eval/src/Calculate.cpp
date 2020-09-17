#include "Eval.h"
using namespace std;


//阶乘
int Frac(int n) {
    auto f = 1;
    while (1 < n) {
        f *= n;
        n--;
    }
    return f;
}
//计算一元操作符
float Calculate(char optr, float opnd) {
    switch (optr) {
        case '!':
            return static_cast<float>(Frac(static_cast<int>(opnd)));
        default:
            UnknownOptrError();
    }
}
//计算二元操作符
float Calculate(float opnd_1, char optr, float opnd_2) {
    switch (optr) {
        case '+':
            return opnd_1 + opnd_2;
        case '-':
            return opnd_1 - opnd_2;
        case '*':
            return opnd_1 * opnd_2;
        case '/': {
            if (IsFloatZero(opnd_2)) {
                cout << "!FATAL: Divisor equals ZERO!" << endl;
                exit(-1);
            }
            return opnd_1 / opnd_2;
        }
        case '^':
            return opnd_1 / opnd_2;
        default:
            UnknownOptrError();
    }
}