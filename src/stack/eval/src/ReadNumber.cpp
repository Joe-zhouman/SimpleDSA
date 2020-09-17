#include "Eval.h"
using namespace simple_dsa;
using namespace std;
//数字字符转为浮点数
float Char2Num(char p) { return static_cast<float>(p - '0'); }
//将数字读入操作数栈
void ReadNumber(char*& exp, StackL<float>& opnd) {
    opnd.Push(Char2Num(*exp));
    while (isdigit(*(++exp))) {
        opnd.Push(opnd.Pop() * 10 + Char2Num(*exp));
    }
    if ('.' != *exp) return;
    float fraction = 1;
    while (isdigit(*(++exp))) {
        fraction /= 10;
        opnd.Push(opnd.Pop() + Char2Num(*exp) * fraction);
    }
}