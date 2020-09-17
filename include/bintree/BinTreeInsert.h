#pragma once
namespace my_dsa {

	template <typename T>
	BinNode<T>* BinTree<T>::InsertAsRoot(T const& e) {
		size_ = 1;
		return root_ = new BinNode<T>(e);
	}

	template <typename T>
	BinNode<T>* BinTree<T>::InsertAsLeftChild(BinNode<T>* x, T const& e) {
		size_++;
		x->InsertAsLeftChild(e);
		UpdateHeightAbove(x);
		return x->left_child_;
	}

	template <typename T>
	BinNode<T>* BinTree<T>::InsertAsRightChild(BinNode<T>* x, T const& e) {
		size_++;
		x->InsertAsRightChild(e);
		UpdateHeightAbove(x);
		return x->right_child_;
	}
}
