#pragma once
namespace simple_dsa {

template <typename T>
ListNodePosi<T> List<T>::InsertAsFirst(T const& e) {
    size_++;
    return header_->InsertAsSucc(e);
}  // e当作首节点插入

template <typename T>
ListNodePosi<T> List<T>::InsertAsLast(T const& e) {
    size_++;
    return trailer_->InsertAsPred(e);
}  // e当作末节点插入

template <typename T>
ListNodePosi<T> List<T>::InsertA(ListNodePosi<T> p, T const& e) {
    size_++;
    return p->InsertAsSucc(e);
}  // e当作p的后继插入（After）

template <typename T>
ListNodePosi<T> List<T>::InsertB(ListNodePosi<T> p, T const& e) {
    size_++;
    return p->InsertAsPred(e);
}  // e当作p的前驱插入（Before）

}  // namespace simple_dsa