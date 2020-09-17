#pragma once
#include "VectorInit.h"
namespace simple_dsa {
template <typename T>
class Vector {
protected:
    Rank size_;
    int capacity_;
    T *elem_;
    void CopyFrom(T const *copiedArray, Rank lo, Rank hi);
    void Expand();
    void Shrink();
    Rank Max(Rank lo, Rank hi);
    Rank Bubble(Rank lo, Rank hi);
    void BubbleSort(Rank lo, Rank hi);
    void SelectionSort(Rank lo, Rank hi);
    void Merge(Rank lo, Rank mi, Rank hi);
    void MergeSort(Rank lo, Rank hi);
    void HeapSort(Rank lo, Rank hi);
    Rank Partition(Rank lo, Rank hi);
    void QuickSort(Rank lo, Rank hi);
    void ShellSort(Rank lo, Rank hi);

public:
    //构造函数
    explicit Vector(int c = kDefaultCapacity, int s = 0, T v = 0) {
        elem_ = new T[capacity_ = c];
        for (size_ = 0; size_ < s; elem_[size_++] = v)
            ;
    }

    Vector(T const *a, Rank n) { CopyFrom(a, 0, n); }
    Vector(T const *a, Rank lo, Rank hi) { CopyFrom(a, lo, hi); }
    Vector(Vector<T> const &V) { CopyFrom(V.elem_, 0, V.size_); }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { CopyFrom(V.elem_, lo, hi); }
    //析构函数
    ~Vector() { delete[] elem_; }
    // 只读访问接口
    // #向量大小
    Rank Size() const { return size_; }    //规模
    bool Empty() const { return !size_; }  //判空
    int Disordered() const;
    // 无序向量整体查找
    Rank Find(T const &e) const { return Find(e, 0, size_); }
    // 无序向量区间查找
    Rank Find(T const &e, Rank lo, Rank hi) const;
    // 有序向量整体查找
    Rank Search(T const &e) const {
        return Search(e, SearchMethod::DEFAULT);
    }

    Rank Search(T const &e, SearchMethod method) const {
        return (0 >= size_) ? -1 : Search(e, 0, size_, method);
    }

    // 有序向量区间查找
    Rank Search(T const &e, Rank lo, Rank hi, SearchMethod method) const;

    Rank Search(T const &e, Rank lo, Rank hi) const {
        return Search(e, lo, hi, SearchMethod::DEFAULT);
    }

    // 重载下标操作符，可以类似于数组形式引用各元素
    T &operator[](Rank r);
    // 重载下标操作符，仅限于做右值的重载版本
    const T &operator[](Rank r) const;
    // 重载赋值操作符，以便直接克隆向量
    Vector<T> &operator=(Vector<T> const &);
    // 删除秩为r的元素
    T Remove(Rank r);
    // 删除秩在区间[lo, hi)之内的元素
    int Remove(Rank lo, Rank hi);
    // r位置插入
    Rank Insert(Rank r, T const &e);
    // 默认作为末元素插入
    Rank Insert(T const &e) { return Insert(size_, e); }

    // 对[lo, hi)排序,可选择排序方法
    void Sort(Rank lo, Rank hi, SortMethod method);
    // 对[lo, hi)排序, 使用默认方法
    void Sort(Rank lo, Rank hi) { Sort(lo, hi, SortMethod::DEFAULT); }
    // 整体排序, 可选择排序方法
    void Sort(SortMethod method) { Sort(0, size_, method); }
    // 整体排序，使用默认方法
    void Sort() { Sort(0, size_, SortMethod::DEFAULT); }

    // 对[lo, hi)置乱
    void Unsort(Rank lo, Rank hi);
    // 整体置乱
    void Unsort() { Unsort(0, size_); }

    // 无序去重
    int Deduplicate();
    // 有序去重
    int Uniquify();

    // 使用函数指针遍历，只读或局部性修改
    void Traverse(void (*visit)(T &));
    // ##使用函数对象遍历，可全局性修改
    template <typename Visit>
    void Traverse(Visit &);
};

}  // namespace simple_dsa
#include "VectorImplementation.h"
