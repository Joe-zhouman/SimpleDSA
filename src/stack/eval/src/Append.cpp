#include"Eval.h"
using namespace std;
//在字符串数组后面添加字符
void Append(string& rpn, char optr){
    rpn += optr;
}
//在字符串数组后面添加数字
void Append(string& rpn, float opnd) {
    char buf[64];
    if(opnd != static_cast<float>(static_cast<int>(opnd))){
        sprintf(buf, "%.2f\0",opnd);
    }else{
        sprintf(buf, "%d\0", static_cast<int>(opnd));
    }
    rpn.append(buf);
    rpn += ',';
}