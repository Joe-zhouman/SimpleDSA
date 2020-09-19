/*********************SimpleDSA************************/
/*    A simple implemention of `data structure and    */
/*  algorithm` in Cpp form                            */
/*********************About Me*************************/
/* *Author*     : Joe, Zhou Man                       */
/* *Email*      : man.man.man.man.a@gmail.com         */
/* *Email*      : joe_zhouman@foxmail.com             */
/* *QQ*         : 1592020915                          */
/* *Weibo*      : @zhouman_LFC                        */
/* *Twitter*    : @zhouman_LFC                        */
/* *Tiktok*     : @JOE.ZM                             */
/* *Website*    : www.joezhouman.com                  */
/* *Github*     : https://github.com/Joe-zhouman      */
/* *LeetCode*   : https://leetcode-cn.com/u/joe_zm/   */
/* *Bilibili*   : https://space.bilibili.com/2743678  */
/******************************************************/
/*                  不务正业的科研狗                     */
/*            You'll never walk alone                 */
/******************************************************/
#pragma once
#ifndef _SORT_SELECTION_H_
#define _SORT_SELECTION_H_
namespace simple_dsa {

template <typename T>
Rank Vector<T>::Max(Rank lo, Rank hi) {
    if (hi - lo < 1) return -1;
    if (1 == hi - lo) return lo;
    Rank max_idx = --hi;
    while (lo < hi--) {
        if (elem_[max_idx] < elem_[hi]) max_idx = hi;
    }
    return max_idx;
}
template <typename T>
void Vector<T>::SelectionSort(Rank lo, Rank hi) {
    while (1 < hi - lo) {
        std::swap(elem_[Max(lo, hi)], elem_[--hi]);
    }
}
}  // namespace simple_dsa
#endif  //_SORT_SELECTION_H_