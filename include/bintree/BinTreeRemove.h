#pragma once
namespace my_dsa {

	template <typename T>
	static int RemoveAt(BinNode<T>* x) {
		if (!x)
			return 0;
		int n = 1 + RemoveAt(x->left_child_) + RemoveAt(x->right_child_);
		release(x->data_);
		release(x);
		return n;
	};

	template <typename T>
	int BinTree<T>::Remove(BinNode<T>* x) {
		FromParentTo(x) = nullptr;
		UpdateHeightAbove(x->parent_);
		const int n = RemoveAt(x);
		size_ -= n;
		return n;
	}

	template <typename T>
	BinTree<T>* BinTree<T>::Secede(BinNode<T>* x) {
		FromParentTo(x) = nullptr;
		UpdateHeightAbove(x->parent_);
		BinTree<T>* t = new BinTree<T>;
		t->root_ = x;
		x->parent_ = nullptr;
		t->size_ = x->Size();
		size_ -= t->size_;
		return t;
	}

}
