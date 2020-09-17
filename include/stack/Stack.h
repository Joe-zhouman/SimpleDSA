#pragma once


#ifndef _STACK_H_
#define _STACK_H_
#include "../vector/Vector.h"
// code
namespace simple_dsa {
template <typename T>
class Stack : public Vector<T> {
public:
    void Push(T const& e) { this->Insert(this->size_, e); }
    T Pop() { return this->Remove(this->size_ - 1); }
    T& Top() { return *this[this->size_ - 1]; }
};
}  // namespace simple_dsa
#endif  //_STACK_H_