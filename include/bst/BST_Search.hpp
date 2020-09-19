#pragma once
#ifndef _BST_SEARCH_HPP_
#define _BST_SEARCH_HPP_
namespace simple_dsa {
template <typename T>
static BinNodePosi<T>& SearchIn(BinNodePosi<T>& v, const T& e,
                                BinNodePosi<T>& hot) {
    if (!v || (e == v->data_)) return v;
    hot = v;
    return SearchIn((e < v->data_ ? v->left_child_ : v->right_child_), e, hot);
}
template <typename T>
BinNodePosi<T>& BST<T>::Search(const T& e) {
    return SearchIn(root_, e, hot_ = nullptr);
}

}  // namespace simple_dsa
#endif  //_BST_SEARCH_HPP_