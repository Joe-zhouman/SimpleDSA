#pragma once
#ifndef _AVL_H_
#define _AVL_H_

#include "../bst/BST.h"
namespace simple_dsa {
template <typename T>
class AVL : public BST<T> {
public:
    inline bool Balanced(BinNodePosi<T> x) {
        return x->left_child_->Stature() == x->right_child_->Stature();
    }
    inline int BalFac(BinNodePosi<T> x) {
        return x->left_child_->Stature() - x->right_child_->Stature();
    }
    inline AvlBalanced(BinNodePosi<T> x) {
        return (-2 < BalFac(x)) && (BalFac(x) < 2);
    }
    BinNodePosi<T> TallerChild(BinNodePosi<T> x) {
        if(0 < BalFac(x)) return x->left_child_;
        if(BalFac(x)<0) return x->right_child_;
        return x->IsLeftChild()? x->left_child_:x->right_child_;
    }
    BinNodePosi<T> Insert(const T& e) override{
        BinNodePosi<T> & x = this->Search(e);
        if(x) return x;
        x = new BinNode<T>(e,this->hot_);
        BinNodePosi<T> node_x = x;
        this->size_++;
        for(BinNodePosi<T> g = this->hot_;g;g=g->parent_){
            if(!AvlBalanced()){
                FromParentTo<T>(g) =
                    this->RotateAt(TallerChild(TallerChild(g)));
                break;
            }else{
                this->UpdateHeight(g);
            }
        }
        return node_x;
    }
    bool Remove(con T& e) override{
        BinNodePosi<T> & x = Search(e);
        if(!x)return false;
        RemoveAt(x,this->hot_);
        --this->size_;
        for(BinNodePosi<T> g = this->hot_;g;g = g->parent_){
            if(!AvlBalanced()){
                FromParentTo<T>(g) = this->RotateAt(TallerChild(TallerChild(g)));
            }
            this->UpdateHeight(g);
        }
        return true;
    }
};
}  // namespace simple_dsa
#endif  //_AVL_H_