#include "Eval.h"
using namespace simple_dsa;
using namespace std;
float Evaluate(char* exp, string& rpn) {
    StackL<float> opnd;
    StackL<char> optr;
    optr.Push('\0');
    while (!optr.Empty()) {
        if (isdigit(*exp)) {
            ReadNumber(exp, opnd);

            Append(rpn, opnd.Top());
        } else {
            
            switch (OrderBetween(optr.Top(), *exp)) {
                case '<': {
                    optr.Push(*exp);
                    exp++;
                } break;
                case '=': {
                    optr.Pop();
                    exp++;
                } break;
                case '>': {
                    char op = optr.Pop();
                    Append(rpn, op);
                    if (IsUnaryOperator(op)) {
                        float num = opnd.Pop();
                        opnd.Push(Calculate(op, num));
                    } else {
                        float num2 = opnd.Pop();
                        float num1 = opnd.Pop();
                        opnd.Push(Calculate(num1, op, num2));
                    }
                } break;
                default:
                    UnknownOptrError();
            }
        }
    }
    return opnd.Pop();
}
