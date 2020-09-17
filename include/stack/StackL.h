/*
 * * 利用链表实现`栈`结构
 */
#pragma once

#ifndef _STACK_L_H_
#define _STACK_L_H_

#include "../list/List.h"

namespace simple_dsa {
template <typename T>
class StackL : public List<T> {
public:
    void Push(T const& e) { this->InsertAsLast(e); }
    T Pop() { return this->Remove(this->Last()); }
    T& Top() { return this->Last()->data_; }
};
}  // namespace simple_dsa
#endif  //_STACK_L_H_