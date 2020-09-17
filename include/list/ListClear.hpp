#pragma once
#ifndef _LIST_CLEAR_HPP_
#define _LIST_CLEAR_HPP_
namespace simple_dsa{
template <typename T>
int List<T>::Clear() {
    int oldSize = size_;
    while (0 < size_) {
        Remove(header_->succ_);
    }
    return oldSize;
}
} //namespace simple_dsa
#endif //_LIST_CLEAR_HPP_