/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once
#include <cstddef>
namespace simple_dsa {

typedef int Rank;  //秩

template <typename T>
struct ListNode {  //列表节点模板类（以双向链表形式实现）
    // 成员
    T data_;
    ListNode<T> *pred_;
    ListNode<T> *succ_;  //数值、前驱、后继
                         // 构造函数
    ListNode() {}        //针对header和trailer的构造
    ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr)
        : data_(e), pred_(p), succ_(s) {}  //默认构造器
                                           // 操作接口
    ListNode<T> *InsertAsPred(T const &e);  //紧靠当前节点之前插入新节点
    ListNode<T> *InsertAsSucc(T const &e);  //紧随当前节点之后插入新节点
};
template <typename T>
using ListNodePosi = ListNode<T> *;
template <
    typename T>  //将e紧靠当前节点之前插入于当前节点所属列表（设有哨兵头节点header）
ListNodePosi<T> ListNode<T>::InsertAsPred(T const &e) {
    ListNodePosi<T> x = new ListNode(e, pred_, this);  //创建新节点
    pred_->succ_ = x;
    pred_ = x;  //设置正向链接
    return x;   //返回新节点的位置
}
template <
    typename T>  //将e紧随当前节点之后插入于当前节点所属列表（设有哨兵尾节点trailer）
ListNodePosi<T> ListNode<T>::InsertAsSucc(T const &e) {
    ListNodePosi<T> x = new ListNode(e, this, succ_);  //创建新节点
    succ_->pred_ = x;
    succ_ = x;  //设置逆向链接
    return x;   //返回新节点的位置
}

}  // namespace simple_dsa