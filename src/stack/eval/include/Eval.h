#pragma once
#ifndef _EVAL_H_
#define _EVAL_H_

#include <stack/StackL.h>

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Operator.h"

//表达式求值，并输出逆波兰表达式
float Evaluate(char* exp, std::string& rpn);
//逆波兰表达式求值
float RpnEval(char* rpn);

//操作符字符转化为枚举
Operator Char2Optr(char optr);
//输出两个操作符之间的大小关系
char OrderBetween(char optr_1, char optr_2);

//数字字符转为浮点数
float Char2Num(char p);
//将数字读入操作数栈
void ReadNumber(char*& exp, simple_dsa::StackL<float>& opnd);
//在字符串数组后面添加字符
void Append(std::string& rpn, char optr);
//在字符串数组后面添加数字
void Append(std::string& rpn, float opnd);

//计算一元操作符
float Calculate(char optr, float opnd);
//计算二元操作符
float Calculate(float opnd_1, char optr, float opnd_2);
//阶乘
int Frac(int n);

//判断是否为一元操作符
bool IsUnaryOperator(char op);
//抛出未知操作符错误
void UnknownOptrError();
//判断浮点数是否为0
bool IsFloatZero(float num);

#endif  //_EVAL_H_