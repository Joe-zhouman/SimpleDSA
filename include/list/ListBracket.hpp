#pragma once
namespace simple_dsa {

template <typename T>
T& List<T>::operator[](Rank r) const {  // assert: 0 <= r < size
    ListNodePosi<T> p = First();        //从首节点出发
    while (0 < r--) p = p->succ_;       //顺数第r个节点即是
    return p->data_;  //目标节点，返回其中所存元素
}
}  // namespace simple_dsa