#pragma once
namespace my_dsa {

	template <typename T>
	template <typename Visit>
	void BinNode<T>::TraversalPre(Visit& vst, TraversalMethod method) {
		switch (method) {
			case TraversalMethod::RECUR :
				PreRecur(this, vst);
				return;
			case TraversalMethod::TAIL :
				PreTail(this, vst);
				return;
			case TraversalMethod::VISIT_ALONG :
				PreVisitAlong(this, vst);
				return;
			default :
				throw"error traversal method";
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::PreRecur(BinNode<T>* x, Visit& vst) {
		if (!x)
			return;
		vst(x->data_);
		PreRecur(x->left_child_, vst);
		PreRecur(x->right_child_, vst);
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::PreTail(BinNode<T>* x, Visit& vst) {
		std::stack<BinNode<T>*> node_stack;
		if (x)
			node_stack.push(x);
		while (!node_stack.empty()) {
			x = node_stack.top();
			node_stack.pop();
			vst(x->data_);
			if (x->HasRightChild())
				node_stack.push(x->right_child_);
			if (x->HasLeftChild())
				node_stack.push(x->left_child_);
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::VisitAlongLeftBranch(BinNode<T>* x, Visit& vst, std::stack<BinNode<T>*>& s) {
		while (x) {
			vst(x->data_);
			s.push(x->right_child_);
			x = x->left_child_;
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::PreVisitAlong(BinNode<T>* x, Visit& vst) {
		std::stack<BinNode<T>*> node_stk;
		while (true) {
			VisitAlongLeftBranch(x, vst, node_stk);
			if (node_stk.empty())
				return;
			x = node_stk.top();
			node_stk.pop();
		}
	}
}
