#include"Eval.h"

Operator Char2Optr(char optr){
    switch (optr)
    {
    case '+':
        return Operator::ADD;
    case '-':
        return Operator::SUB;
    case '*':
        return Operator::MUL;
    case '/':
        return Operator::DIV;
    case '^':
        return Operator::POW;
    case '!':
        return Operator::FAC;
    case '(':
        return Operator::L_P;
    case ')':
        return Operator::R_P;
    case '\0':
        return Operator::EOE;
    default:
        break;
    }
}
char OrderBetween(char optr_1, char optr_2){
    return Order[Char2Optr(optr_1)][Char2Optr(optr_2)];
}
