#include "Eval.h"
using namespace simple_dsa;
using namespace std;

float RpnEval(char* rpn) {
    StackL<float> opnd;
    while ('\0' != *rpn) {
        if (isdigit(*rpn)) {
            ReadNumber(rpn, opnd);
        } else {
            char op = *rpn;
            if (op == ',') {
                rpn++;
                continue;
            }
            if (IsUnaryOperator(op)) {
                float num = opnd.Pop();
                opnd.Push(Calculate(op, num));
            } else {
                float num2 = opnd.Pop();
                float num1 = opnd.Pop();
                opnd.Push(Calculate(num1, op, num2));
            }
            rpn++;
        }
    }
    return opnd.Pop();
}
