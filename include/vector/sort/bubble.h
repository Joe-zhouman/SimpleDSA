#pragma once
#ifndef _SORT_BUBBLE_H_
#define _SORT_BUBBLE_H_
namespace simple_dsa{
    //起泡排序法;
    template <typename T>
    Rank Vector<T>::Bubble(Rank lo, Rank hi)
    {
        Rank last = lo;
        while (++lo < hi)
        {
            if (elem_[lo - 1] > elem_[lo])
            {
                last = lo;
                std::swap(elem_[lo - 1], elem_[lo]);
            }
        }
        return last;
    }

    template <typename T>
    void Vector<T>::BubbleSort(Rank lo, Rank hi)
    {
        //assert: 0 <= lo < hi <= size
        for (Rank last = --hi; lo < hi; hi = last)
            for (Rank i = last = lo; i < hi; i++)
                if (elem_[i] > elem_[i + 1])             //若逆序，则
                    std::swap(elem_[last = i], elem_[i + 1]); //经交换使局部有序
    }

} //namespace simple_dsa
#endif //_SORT_BUBBLE_H_