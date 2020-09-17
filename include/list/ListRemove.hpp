#pragma once
#ifndef _LIST_REMOVE_HPP_
#define _LIST_REMOVE_HPP_
namespace simple_dsa {
template <typename T>
T List<T>::Remove(ListNodePosi<T> p) {  //删除合法节点p，返回其数值
    T e = p->data_;  //备份待删除节点的数值（假定T类型可直接赋值）
    p->pred_->succ_ = p->succ_;
    p->succ_->pred_ = p->pred_;  //后继、前驱
    delete p;
    size_--;   //释放节点，更新规模
    return e;  //返回备份的数值
}
}  // namespace simple_dsa
#endif  //_LIST_REMOVE_HPP_