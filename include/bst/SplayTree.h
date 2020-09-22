#pragma once
#ifndef _SPLAY_TREE_H_
#define _SPLAY_TREE_H_
#include "../bst/BST.h"
namespace simple_dsa {

template <typename T>
inline void AttachAsLeftChild(BinNodePosi<T> p, BinNodePosi<T> lc) {
    p->left_child_ = lc;
    if (lc) lc->parent_ = p;
}

template <typename T>
inline void AttachAsRightChild(BinNodePosi<T> p, BinNodePosi<T> rc) {
    p->right_child_ = rc;
    if (rc) rc->parent_ = p;
}
template <typename T>
class SplayTree : public BST<T> {
protected:
    BinNodePosi<T> Splay(BinNodePosi<T> v) {
        if (!v) return nullptr;
        BinNodePosi<T> p;
        BinNodePosi<T> g;
        for (p = v->parent_, g = p->parent_; p && g;) {
            BinNodePosi<T> gg_parent = g->parent_;
            if (v->IsLeftChild()) {
                if (p->IsLeftChild()) {
                    AttachAsLeftChild(g, p->right_child_);
                    AttachAsLeftChild(p, v->right_child_);
                    AttachAsRightChild(p, g);
                    AttachAsRightChild(v, p);
                } else {
                    AttachAsLeftChild(p, v->right_child_);
                    AttachAsRightChild(g, v->left_child_);
                    AttachAsLeftChild(v, g);
                    AttachAsRightChild(v, p);
                }
            } else if (p->IsRightChild()) {
                AttachAsRightChild(p, v->left_child_);
                AttachAsRightChild(p, v->left_child_);
                AttachAsLeftChild(p, g);
                AttachAsLeftChild(v, p);
            } else {
                AttachAsRightChild(p, v->right_child_);
                AttachAsLeftChild(g, v->right_child_);
                AttachAsRightChild(v, g);
                AttachAsLeftChild(v, p);
            }
            if (!gg_parent)
                v->parent_ = nullptr;
            else {
                (g == gg_parent->left_child_)
                    ? AttachAsLeftChild(gg_parent, v)
                    : AttachAsRightChild(gg_parent, v);
            }
            this->UpdateHeight(g);
            this->UpdateHeight(p);
            this->UpdateHeight(v);
        }
        if (p = v->parent_) {
            if (v->IsLeftChild()) {
                AttachAsLeftChild(p, v->right_child_);
                AttachAsRightChild(v, p);
            } else {
                AttachAsRightChild(p, v->left_child_);
                AttachAsLeftChild(v, p);
            }
            this->UpdateHeight(p);
            this->UpdateHeight(v);
        }
        v->parent_ = nullptr;
        return v;
    }

public:
    BinNodePosi<T>& Search(const T& e) override {
        BinNodePosi<T> p = SearchIn(this->root_, e, this->hot_ = nullptr);
        this->root_ = Splay(p ? p : this->hot_);
        return this->root_;
    }
    BinNodePosi<T> Insert(const T& e) override {
        if (!this->root_) {
            ++this->size_;
            return this->root_ = new BinNode<T>(e);
        }
        if (e == Search(e)->data_) return this->root_;
        ++this->size_;
        BinNodePosi<T> t = this->root_;
        if (this->root_->data_ < e) {
            this->root_ = new BinNode<T>(e, nullptr, t, t->right_child_);
            t->parent_ = this->root_;
            if (t->HasRightChild()) {
                t->right_child_->parent_ = this->root_;
                t->right_child_ = nullptr;
            }
        } else {
            this->root_ = new BinNode<T>(e, nullptr, t, t->left_child_);
            t->parent_ = this->root_;
            if (t->HasLeftChild()) {
                t->left_child_->parent_ = this->root_;
                t->left_child_ = nullptr;
            }
        }
        this->UpdateHeightAbove(t);
        return this->root_;
    }

    bool Remove(const T& e) override;
};
}  // namespace simple_dsa
#endif  //_SPLAY_TREE_H_