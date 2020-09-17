#pragma once
#ifndef _LIST_SORT_HPP_
#define _LIST_SORT_HPP_
namespace simple_dsa {
template <typename T>
void List<T>::Sort(ListNodePosi<T> p, int n, SortMethod method) {
    switch (method) {
        case SortMethod::INSERTION:
            InsertionSort(p, n);
            break;
        case SortMethod::MERGE:
            /* code */
            break;
        case SortMethod::SELECTION:
            SelectionSort(p, n);
            break;
        default:
            break;
    }
}
template <typename T>
void List<T>::InsertionSort(ListNodePosi<T> p, int n) {
    for (size_t r = 0; r < n; r++) {
        InsertA(Search(p->data_, r, p), p->data_);
        p = p->succ_;
        Remove(p->pred_);
    }
}
template <typename T>
void List<T>::SelectionSort(ListNodePosi<T> p, int n) {
    auto head = p->pred_;
    auto tail = p;
    for (size_t i = 0; i < n; i++) {
        tail = tail->succ_;
    }
    while (1 < n) {
        auto max = SelectMax(head->succ_, n);
    }
}
template <typename T>
ListNodePosi<T> List<T>::SelectMax(ListNodePosi<T> p, int n) {
    auto m = p;
    for (auto cur = p; 1 < n; n--) {
        cur = cur->succ_;
        if (m->data_ <= cur->data_) m = cur;
    }
    return m;
}

template <typename T>
void List<T>::MergeSort(ListNodePosi<T>& p, int n) {
    if (n < 2) return;
    int m = n >> 1;
    auto q = p;
    for (size_t i = 0; i < m; i++) q = q->succ_;
    MergeSort(p, m);
    MergeSort(q, n - m);
    Merge(p, m, *this, q, n - m);
}
template <typename T>
void List<T>::Merge(ListNodePosi<T>& p, int n, List<T>& L, ListNodePosi<T> q,
                    int m) {
    auto head = p->pred_;
    while (0 < m) {
        if (0 < n && p->data_ <= q->data_) {
            p = p->succ_;
            if (q == p) break;
            n--;
        } else {
            q = q->succ_;
            InsertB(p, L.Remove(q->pred_));
            m--;
        }
    }
    p = head->succ_;
}
}  // namespace simple_dsa
#endif  //_LIST_SORT_HPP_
