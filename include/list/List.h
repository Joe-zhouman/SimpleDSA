#pragma once

#include "ListNode.h"  //引入列表节点类
namespace simple_dsa {

enum class SortMethod { INSERTION, MERGE, SELECTION, DEFAULT = INSERTION };

template <typename T>
class List {  //列表模板类

private:
    int size_;
    ListNodePosi<T> header_;
    ListNodePosi<T> trailer_;  //规模、头哨兵、尾哨兵

protected:
    void Init();                           //列表创建时的初始化
    int Clear();                           //清除所有节点
    void CopyNodes(ListNodePosi<T>, int);  //复制列表中自位置p起的n项
    void Merge(ListNodePosi<T>&, int, List<T>&, ListNodePosi<T>, int);  //归并
    void MergeSort(ListNodePosi<T>&, int);  //对从p开始连续的n个节点归并排序
    void SelectionSort(ListNodePosi<T>, int);  //对从p开始连续的n个节点选择排序
    void InsertionSort(ListNodePosi<T>, int);  //对从p开始连续的n个节点插入排序

public:
    // 构造函数
    List() { Init(); }                      //默认
    List(List<T> const& L);                 //整体复制列表L
    List(List<T> const& L, Rank r, int n);  //复制列表L中自第r项起的n项
    List(ListNodePosi<T> p, int n);  //复制列表中自位置p起的n项
    // 析构函数
    ~List();  //释放（包含头、尾哨兵在内的）所有节点
    // 只读访问接口
    Rank Size() const { return size_; }        //规模
    bool Empty() const { return size_ <= 0; }  //判空
    T& operator[](Rank r) const;  //重载，支持循秩访问（效率低）
    ListNodePosi<T> First() const { return header_->succ_; }  //首节点位置
    ListNodePosi<T> Last() const { return trailer_->pred_; }  //末节点位置
    bool Valid(ListNodePosi<T> p)  //判断位置p是否对外合法
    {
        return p && (trailer_ != p) && (header_ != p);
    }                                       //将头、尾节点等同于NULL
    ListNodePosi<T> Find(T const& e) const  //无序列表查找
    {
        return Find(e, size_, trailer_);
    }
    ListNodePosi<T> Find(T const& e, int n,
                         ListNodePosi<T> p) const;  //无序区间查找
    ListNodePosi<T> Search(T const& e) const        //有序列表查找
    {
        return Search(e, size_, trailer_);
    }
    ListNodePosi<T> Search(T const& e, int n,
                           ListNodePosi<T> p) const;  //有序区间查找
    ListNodePosi<T> SelectMax(ListNodePosi<T> p,
                              int n);  //在p及其n-1个后继中选出最大者
    ListNodePosi<T> SelectMax() {
        return SelectMax(header_->succ_, size_);
    }  //整体最大者
    // 可写访问接口
    ListNodePosi<T> InsertAsFirst(T const& e);  //将e当作首节点插入
    ListNodePosi<T> InsertAsLast(T const& e);   //将e当作末节点插入
    ListNodePosi<T> InsertA(ListNodePosi<T> p,
                            T const& e);  //将e当作p的后继插入（After）
    ListNodePosi<T> InsertB(ListNodePosi<T> p,
                            T const& e);  //将e当作p的前驱插入（Before）
    T Remove(ListNodePosi<T> p);  //删除合法位置p处的节点,返回被删除节点
    void Merge(List<T>& L) {
        Merge(First(), Size, L, L.First(), L.size_);
    }                                                        //全列表归并
    void Sort(ListNodePosi<T> p, int n, SortMethod method);  //列表区间排序
    void Sort(SortMethod method) {
        Sort(First(), size_, method);
    }  //列表整体排序
    void Sort(ListNodePosi<T> p, int n) {
        Sort(p, n, SortMethod::DEFAULT);
    }                                           //列表区间排序
    void Sort() { Sort(SortMethod::DEFAULT); }  //列表整体排序
    int Deduplicate();                          //无序去重
    int Uniquify();                             //有序去重
    void Reverse();                             //前后倒置（习题）
    // 遍历
    void Traverse(
        void (*)(T&));  //遍历，依次实施visit操作（函数指针，只读或局部性修改）
    template <typename Visit>  //操作器
    void Traverse(Visit&);  //遍历，依次实施visit操作（函数对象，可全局性修改）
};                          // List
}  // namespace simple_dsa
#include "ListImplementation.h"
