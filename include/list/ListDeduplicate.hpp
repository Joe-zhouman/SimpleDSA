#pragma once
namespace simple_dsa {

template <typename T>
int List<T>::Deduplicate() {
    if (size_ < 2) {
        return 0;
    }
    const int oldSize = size_;
    ListNodePosi<T> p = First();
    for (Rank r = 0; p != trailer_; p = p->succ_)  // O(n)
        if (ListNodePosi<T> q = Find(p->data_, r, p))
            Remove(q);  //此时q与p雷同，但删除前者更为简明
        else
            r++;             // r为无重前缀的长度
    return oldSize - size_;  //删除元素总数
}
}  // namespace simple_dsa