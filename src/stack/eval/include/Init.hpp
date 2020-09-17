#pragma once
#ifndef _INIT_HPP_
#define _INIT_HPP_

#include <iostream>
#include <string>

//输出帮助信息
void PrintHelpInfo() { std::cout << "!TODO" << std::endl; }
//输出参数错误信息
void PrintArgvErrorInfo() {
    std::cout << "!FATAL : Parameters Error" << std::endl;
}

//获取输入的字符串
void GetExpression(char*& exp) { 
    std::cout << "Enter the expression:"; 
    std::cin.get(exp,64);   
}
//去除字符串表达式中的空格
char* RemoveSpace(char* exp) {
    char* p = exp;
    char* q = exp;
    while (true) {
        while (isspace(*q)) q++;
        if ('\0' == *q) {
            *p = '\0';
            return exp;
        }
        *p++ = *q++;
    }
}
#endif  //_INIT_HPP_