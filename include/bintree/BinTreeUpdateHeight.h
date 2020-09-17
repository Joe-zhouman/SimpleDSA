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
namespace simple_dsa {

template <typename T>
int BinTree<T>::UpdateHeight(BinNode<T>* x) {
    return x->height_ = 1 + std::max(x->left_child_->Stature(),
                                     x->right_child_->Stature());
}

template <typename T>
void BinTree<T>::UpdateHeightAbove(BinNode<T>* x) {
    while (x) {
        if (x->height_ == UpdateHeight(x)) return;
        x = x->parent_;
    }
}
}  // namespace simple_dsa
