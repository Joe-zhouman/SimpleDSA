#pragma once
namespace my_dsa {

	template <typename T>
	template <typename Visit>
	void BinNode<T>::TraversalPost(Visit& vst, TraversalMethod method) {
		switch (method) {
			case TraversalMethod::RECUR :
				PostRecur(this, vst);
				return;
			default :
				throw"error traversal method";
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::PostRecur(BinNode<T>* x, Visit& vst) {
		if (!x)
			return;
		InRecur(x->left_child_, vst);
		InRecur(x->right_child_, vst);
		vst(x->data_);
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::PostGoStart(BinNode<T>* x, Visit& vst) {
		std::stack<BinNode<T>*> s;
		if (!x)
			s.push(x);
		while (s.empty()) {
			if (s.top() != x->parent_)
				GoStart<T>(s);
			x = s.top();
			s.pop();
			vst(x->data_);
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::GoStart(std::stack<BinNode<T>*>& s) {
		while (BinNode<T>* x = s.top()) {
			if (x->HasLeftChild()) {
				if (x->HasRightChild())
					s.push(x->right_child_);
				s.push(x->left_child_);
			}
			else
				s.push(x->right_child_);
		}
		s.pop();
	}
}
