#pragma once
#ifndef _BST_INSERT_HPP_
#define _BST_INSERT_HPP_
namespace simple_dsa {
template <typename T>
BinNodePosi<T> BST<T>::Insert(const T& e) {
    x = new BinNode<T>(e,hot_);
    size_++;
    UpdateHeightAbove(x);
    return x;
}
}  // namespace simple_dsa
#endif  //_BST_INSERT_HPP_