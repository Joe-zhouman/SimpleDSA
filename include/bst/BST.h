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
#ifndef _BST_H_
#define _BST_H_
#include "../bintree/BinTree.h"
namespace simple_dsa {
template <typename T>
class BST : public BinTree<T> {
private:
protected:
    BinNodePosi<T> hot_;
    BinNodePosi<T> connect34(BinNodePosi<T> n1, BinNodePosi<T> n2,
                             BinNodePosi<T> n3, BinNodePosi<T> t1,
                             BinNodePosi<T> t2, BinNodePosi<T> t3,
                             BinNodePosi<T> t4, );

public:
    virtual BinNodePosi<T>& Search(const T& e);
    virtual BinNodePosi<T> Insert(const T& e);
    virtual bool Remove(const T& e);
};

}  // namespace simple_dsa
#endif  //_BST_H_