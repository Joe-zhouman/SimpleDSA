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
template <typename Visit>
void BinNode<T>::TraversalIn(Visit& vst, TraversalMethod method) {
    switch (method) {
        case TraversalMethod::RECUR:
            InRecur(this, vst);
            return;
        case TraversalMethod::VISIT_ALONG:
            InGoAlong(this, vst);
            return;
        case TraversalMethod::SUCCEED:
            InSucceed(this, vst);
            return;
        default:
            throw "error traversal method";
    }
}

template <typename T>
template <typename Visit>
void BinNode<T>::InRecur(BinNodePosi<T> x, Visit& vst) {
    if (!x) return;
    InRecur(x->left_child_, vst);
    vst(x->data_);
    InRecur(x->right_child_, vst);
}

template <typename T>
template <typename Visit>
void BinNode<T>::GoAlongLeftBranch(BinNodePosi<T> x, Stack<BinNodePosi<T>>& s) {
    while (x) {
        s.push(x->right_child_);
        x = x->left_child_;
    }
}

template <typename T>
template <typename Visit>
void BinNode<T>::InGoAlong(BinNodePosi<T> x, Visit& vst) {
    Stack<BinNodePosi<T>> node_stk;
    while (true) {
        GoAlongLeftBranch(x, node_stk);
        if (node_stk.empty()) return;
        x = node_stk.Pop();
        vst(x->data_);
        x = x->right_child_;
    }
}

template <typename T>
template <typename Visit>
void BinNode<T>::InSucceed(BinNodePosi<T> x, Visit& vst) {
    auto back_track = false;
    while (true) {
        if (!back_track && x->HasLeftChild()) {
            x = x->left_child_;
        } else {
            vst(x->data_);
            if (x->HasRightChild()) {
                x = x->right_child_;
                back_track = false;
            } else {
                x = x->Succeed();
                if (!x) return;
                back_track = true;
            }
        }
    }
}

}  // namespace simple_dsa
