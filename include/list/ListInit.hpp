#pragma once
#ifndef _LIST_INIT_HPP_
#define _LIST_INIT_HPP_
namespace simple_dsa {
template <typename T>
void List<T>::Init() {
    header_ = new ListNode<T>;
    trailer_ = new ListNode<T>;
    header_->succ_ = trailer_;
    header_->pred_ = nullptr;
    trailer_->succ_ = nullptr;
    trailer_->pred_ = header_;
    size_ = 0;
}
}  // namespace simple_dsa
#endif  //_LIST_INIT_HPP_
