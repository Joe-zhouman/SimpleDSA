#pragma once
namespace my_dsa {

	template <typename T>
	BinNode<T>* BinTree<T>::AttachAsRightChild(BinNode<T>* x, BinTree<T>*& t) {
		if (x->right_child_ = t->root_)
			x->right_child_->parent_ = x;
		size_ += t->size_;
		UpdateHeightAbove(x);
		t->root_ = nullptr;
		t->size_ = 0;
		release(t);
		t = nullptr;
		return x;
	}

	template <typename T>
	BinNode<T>* BinTree<T>::AttachAsLeftChild(BinNode<T>* x, BinTree<T>*& t) {
		if (x->left_child_ = t->root_)
			x->left_child_->parent_ = x;
		size_ += t->size_;
		UpdateHeightAbove(x);
		t->root_ = nullptr;
		t->size_ = 0;
		release(t);
		t = nullptr;
		return x;
	}
}
