#pragma once
namespace my_dsa {
	template <typename T>
	template <typename Visit>
	void BinNode<T>::TraversalIn(Visit& vst, TraversalMethod method) {
		switch (method) {
			case TraversalMethod::RECUR :
				InRecur(this, vst);
				return;
			case TraversalMethod::VISIT_ALONG :
				InGoAlong(this, vst);
				return;
			case TraversalMethod::SUCCEED :
				InSucceed(this, vst);
				return;
			default :
				throw"error traversal method";
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::InRecur(BinNode<T>* x, Visit& vst) {
		if (!x)
			return;
		InRecur(x->left_child_, vst);
		vst(x->data_);
		InRecur(x->right_child_, vst);
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::GoAlongLeftBranch(BinNode<T>* x, std::stack<BinNode<T>*>& s) {
		while (x) {
			s.push(x->right_child_);
			x = x->left_child_;
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::InGoAlong(BinNode<T>* x, Visit& vst) {
		std::stack<BinNode<T>*> node_stk;
		while (true) {
			GoAlongLeftBranch(x, node_stk);
			if (node_stk.empty())
				return;
			x = node_stk.top();
			vst(x->data_);
			node_stk.pop();
			x = x->right_child_;
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::InSucceed(BinNode<T>* x, Visit& vst) {
		auto back_track = false;
		while (true) {
			if (!back_track && x->HasLeftChild()) {
				x = x->left_child_;
			}
			else {
				vst(x->data_);
				if (x->HasRightChild()) {
					x = x->right_child_;
					back_track = false;
				}
				else {
					x = x->Succeed();
					if (!x)
						return;
					back_track = true;
				}
			}
		}
	}

}
