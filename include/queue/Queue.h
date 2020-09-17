#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "../list/List.h"
namespace simple_dsa {
template <typename T>
class Queue : public List<T> {
    void Enqueue(T const& e) { this->InsertAsLast(e); }
    T Dequeue() { return this->Remove(this->First()); }
    T& Front() { return this->First()->data_; }
};
}  // namespace simple_dsa
#endif  //_QUEUE_H_