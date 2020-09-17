#pragma once
namespace my_dsa {

	template <typename T>
	int BinTree<T>::UpdateHeight(BinNode<T>* x) {
		return x->height_ = 1 + std::max(x->left_child_->Stature(), x->right_child_->Stature());
	}

	template <typename T>
	void BinTree<T>::UpdateHeightAbove(BinNode<T>* x) {
		while (x) {
			UpdateHeight(x);
			x = x->parent_;
		}
	}
}
