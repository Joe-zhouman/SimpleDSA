#pragma once
#ifndef _LIST_TRAVERSE_H_
#define _LIST_TRAVERSE_H_
namespace simple_dsa {
template <typename T>
void List<T>::Traverse(void (*visit)(T&)) {
    for (ListNodePosi<T> p = header_->succ_; p != trailer_; p = p->succ_)
        visit(p->data_);
}

template <typename T>
template <typename Visit>
void List<T>::Traverse(Visit& visit) {
    for (ListNodePosi<T> p = header_->succ_; p != trailer_; p = p->succ_)
        visit(p->data_);
}
}  // namespace simple_dsa
#endif  //_LIST_TRAVERSE_H_