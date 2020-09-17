#pragma once
namespace my_dsa {
	template <typename T>
	template <typename Visit>
	void BinNode<T>::TraversalLevel(Visit& vst) {
		std::queue<BinNode<T>*> q;
		q.push(this);
		while (!q.empty()) {
			BinNode<T>* x = q.front();
			q.pop();
			vst(x->data_);
			if (x->HasLeftChild())
				q.push(x->left_child_);
			if (x->HasRightChild())
				q.push(x->right_child_);
		}
	}
}
