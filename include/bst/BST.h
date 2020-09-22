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
    BinNodePosi<T> Connect34(BinNodePosi<T> n0, BinNodePosi<T> n1,
                             BinNodePosi<T> n2, BinNodePosi<T> t0,
                             BinNodePosi<T> t1, BinNodePosi<T> t2,
                             BinNodePosi<T> t3, ) {
        n0->left_child_ = t0;
        if (t0) t0->parent_ = n0;
        n0->right_child_ = t1;
        if (t1) t1->parent_ = n0;
        this->UpdateHeight(a);
        n2->left_child_ = t2;
        if (t2) t2->parent_ = n2;
        n2->right_child_ = t3;
        if (t3) t3->parent_ = n2;
        this->UpdateHeight(n2);
        n1->left_child_ = n0;
        n0->parent_ = n1;
        n1->right_child_ = n2;
        n2->parent_ = n1;
        this->UpdateHeight(b);
    }
    BinNodePosi<T> RotateAt(BinNodePosi<T> v) {
        BinNodePosi<T> p = v->parent_;
        BinNodePosi<T> g = p->parent_;
        if (p->IsLeftChild()) {
            if (v->IsLeftChild()) {
                p->parent_ = g->parent_;
                return Connect34(v, p, g, v->left_child_, v->right_child_,
                                 p->right_child_, g->right_child_);
            } else {
                v->parent_ = g->parent_;
                return Connect34(p, v, g, p->left_child_, v->left_child_,
                                 v->right_child_, g->right_child_);
            }
        } else {
            if (v->IsRightChild()) {
                p->parent_ = g->parent_;
                return Connect34(g, p, v, g->left_child_, p->left_child_,
                                 v->left_child_, v->right_child_);
            } else {
                v->parent_ = g->parent_;
                return Connect34(g, v, p, g->left_child_, v->left_child_,
                                 v->right_child_, p->right_child_);
            }
        }
    }

public:
    virtual BinNodePosi<T>& Search(const T& e) {
        return SearchIn(root_, e, hot_ = nullptr);
    }
    virtual BinNodePosi<T> Insert(const T& e) {
        BinNodePosi<T>& x = Search(e);
        if (x) return x;
        x = new BinNode<T>(e, hot_);
        ++this->size_;
        this->UpdateHeightAbove(x);
        return x;
    }
    virtual bool Remove(const T& e) {
        BinNodePosi<T>& x = Search(e);
        if (!x) return false;
        RemoveAt(x, hot_);
        this->UpdateHeight(hot_);
        return true;
    }
};
template <typename T>
static BinNodePosi<T> RemoveAt(BinNodePosi<T>& x, BinNodePosi<T>& hot) {
    BinNodePosi<T> w = x;
    BinNodePosi<T> succ = nullptr;
    if (!x->HasLeftChild()) {
        x = x->right_child_;
        succ = x;
    } else if (!x->HasRightChild()) {
        x = x->left_child_;
        succ = x;
    } else {
        w = w->Succeed();
        std::swap(x->data_, w->data_);
        BinNodePosi<T> u = w->parent_;
        succ = w->right_child_;
        (u == x ? u->right_child_ : u->left_child_) = succ;
    }
    hot = w->parent_;
    if (succ) succ->parent_ = hot;
    release(w->data_);
    release(w);
    return succ;
}
template <typename T>
static BinNodePosi<T>& SearchIn(BinNodePosi<T>& v, const T& e,
                                BinNodePosi<T>& hot) {
    if (!v || (e == v->data_)) return v;
    hot = v;
    return SearchIn((e < v->data_ ? v->left_child_ : v->right_child_), e, hot);
}
}  // namespace simple_dsa
#endif  //_BST_H_