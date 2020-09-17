#pragma once
namespace simple_dsa {

template <typename T>  //在无序列表内节点p的n个前驱中，找到等于e的最后者
ListNodePosi<T> List<T>::Find(T const& e, int n, ListNodePosi<T> p) const {
    while (0 < n--)
        //（0 <= n <= rank(p) < _size）对于p的最近的n个前驱，从右向左
        if (e == (p = p->pred_)->data_)
            return p;  //逐个比对，直至命中或范围越界
    return nullptr;  // p越出左边界意味着区间内不含e，查找失败
}  //失败时，返回NULL
}  // namespace simple_dsa
