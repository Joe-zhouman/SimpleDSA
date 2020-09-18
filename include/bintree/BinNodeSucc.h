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
BinNodePosi<T> BinNode<T>::Succeed() {
    BinNodePosi<T> s_node = this;
    if (s_node->HasRightChild()) {
        s_node = s_node->right_child_;
        while (s_node->HasLeftChild()) {
            s_node = s_node->left_child_;
        }
    } else {
        while (s_node->IsRightChild()) {
            s_node = s_node->parent_;
        }
        s_node = s_node->parent_;
    }
    return s_node;
}
}  // namespace simple_dsa
