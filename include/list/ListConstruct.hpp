#pragma once
namespace simple_dsa {

template <typename T>
List<T>::List(ListNodePosi<T> p, int n) {
    CopyNodes(p, n);
}

template <typename T>
List<T>::List(List<T> const& L) {
    CopyNodes(L.First(), L.size_);
}

template <typename T>
List<T>::List(List<T> const& L, Rank r, int n) {
    CopyNodes(L[r], n);
}

template <typename T>
List<T>::~List()  //列表析构器
{
    Clear();
    delete header_;
    delete trailer_;
}  //清空列表，释放头、尾哨兵节点
}  // namespace simple_dsa