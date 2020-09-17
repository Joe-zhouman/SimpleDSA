#pragma once
#ifndef _LIST_COPYNODE_HPP_
#define _LIST_COPYNODE_HPP_
namespace simple_dsa {
template <typename T>
void List<T>::CopyNodes(ListNodePosi<T> p, int n) {
    Init();
    while (n--) {
        InsertAsLast(p->data_);
        p = p->succ_;
    }
}
}  // namespace simple_dsa
#endif  //_LIST_COPYNODE_HPP_