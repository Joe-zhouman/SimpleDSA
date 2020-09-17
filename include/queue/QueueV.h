#pragma once
#ifndef _QUEUE_V_H_
#define _QUEUE_V_H_

#include "../vector/Vector.h"

namespace simple_dsa {

template <typename T>
class QueueV : public Vector<T> {
public:
    void Enqueue(T const& e) { this->Insert(this->size_, e); }
    T Dequeue() { return this->Remove(0); }
    T& Front() { return *this[0]; }
};

}  // namespace simple_dsa
#endif  //_QUEUE_V_H_