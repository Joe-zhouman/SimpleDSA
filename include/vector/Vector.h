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
    //���캯��
    explicit Vector(int c = kDefaultCapacity, int s = 0, T v = 0) {
        elem_ = new T[capacity_ = c];
        for (size_ = 0; size_ < s; elem_[size_++] = v)
            ;
    }

    Vector(T const *a, Rank n) { CopyFrom(a, 0, n); }
    Vector(T const *a, Rank lo, Rank hi) { CopyFrom(a, lo, hi); }
    Vector(Vector<T> const &V) { CopyFrom(V.elem_, 0, V.size_); }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { CopyFrom(V.elem_, lo, hi); }
    //��������
    ~Vector() { delete[] elem_; }
    // ֻ�����ʽӿ�
    // #������С
    Rank Size() const { return size_; }    //��ģ
    bool Empty() const { return !size_; }  //�п�
    int Disordered() const;
    // ���������������
    Rank Find(T const &e) const { return Find(e, 0, size_); }
    // ���������������
    Rank Find(T const &e, Rank lo, Rank hi) const;
    // ���������������
    Rank Search(T const &e) const {
        return Search(e, SearchMethod::DEFAULT);
    }

    Rank Search(T const &e, SearchMethod method) const {
        return (0 >= size_) ? -1 : Search(e, 0, size_, method);
    }

    // ���������������
    Rank Search(T const &e, Rank lo, Rank hi, SearchMethod method) const;

    Rank Search(T const &e, Rank lo, Rank hi) const {
        return Search(e, lo, hi, SearchMethod::DEFAULT);
    }

    // �����±������������������������ʽ���ø�Ԫ��
    T &operator[](Rank r);
    // �����±������������������ֵ�����ذ汾
    const T &operator[](Rank r) const;
    // ���ظ�ֵ���������Ա�ֱ�ӿ�¡����
    Vector<T> &operator=(Vector<T> const &);
    // ɾ����Ϊr��Ԫ��
    T Remove(Rank r);
    // ɾ����������[lo, hi)֮�ڵ�Ԫ��
    int Remove(Rank lo, Rank hi);
    // rλ�ò���
    Rank Insert(Rank r, T const &e);
    // Ĭ����ΪĩԪ�ز���
    Rank Insert(T const &e) { return Insert(size_, e); }

    // ��[lo, hi)����,��ѡ�����򷽷�
    void Sort(Rank lo, Rank hi, SortMethod method);
    // ��[lo, hi)����, ʹ��Ĭ�Ϸ���
    void Sort(Rank lo, Rank hi) { Sort(lo, hi, SortMethod::DEFAULT); }
    // ��������, ��ѡ�����򷽷�
    void Sort(SortMethod method) { Sort(0, size_, method); }
    // ��������ʹ��Ĭ�Ϸ���
    void Sort() { Sort(0, size_, SortMethod::DEFAULT); }

    // ��[lo, hi)����
    void Unsort(Rank lo, Rank hi);
    // ��������
    void Unsort() { Unsort(0, size_); }

    // ����ȥ��
    int Deduplicate();
    // ����ȥ��
    int Uniquify();

    // ʹ�ú���ָ�������ֻ����ֲ����޸�
    void Traverse(void (*visit)(T &));
    // ##ʹ�ú��������������ȫ�����޸�
    template <typename Visit>
    void Traverse(Visit &);
};

}  // namespace simple_dsa
#include "VectorImplementation.h"
