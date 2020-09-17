#pragma once
#include "MethodEnum.h"
#include <stack>
#include <queue>

namespace my_dsa {
	template <typename T>
	class BinNode {

		template <typename Visit>
		void PreRecur(BinNode<T>* x, Visit& vst);
		template <typename Visit>
		void PreTail(BinNode<T>* x, Visit& vst);
		template <typename Visit>
		void PreVisitAlong(BinNode<T>* x, Visit& vst);

		template <typename Visit>
		void InRecur(BinNode<T>* x, Visit& vst);
		template <typename Visit>
		void InGoAlong(BinNode<T>* x, Visit& vst);
		template <typename Visit>
		static void InSucceed(BinNode<T>* x, Visit& vst);

		template <typename Visit>
		void PostRecur(BinNode<T>* x, Visit& vst);
		template <typename Visit>
		void PostGoStart(BinNode<T>* x, Visit& vst);

		template <typename Visit>
		static void VisitAlongLeftBranch(BinNode<T>* x, Visit& vst, std::stack<BinNode<T>*>& s);
		template <typename Visit>
		static void GoAlongLeftBranch(BinNode<T>* x, std::stack<BinNode<T>*>& s);
		template <typename Visit>
		static void GoStart(std::stack<BinNode<T>*>& s);
	public:
		T data_;
		BinNode<T>* parent_;
		BinNode<T>* left_child_;
		BinNode<T>* right_child_;
		int height_;
		int null_path_len_;
		Color color_;

		BinNode() : parent_(nullptr),
		            left_child_(nullptr),
		            right_child_(nullptr),
		            height_(0),
		            null_path_len_(1),
		            color_(Color::RED) { }

		explicit BinNode(
			T e,
			BinNode<T>* p = nullptr,
			BinNode<T>* lc = nullptr,
			BinNode<T>* rc = nullptr,
			int h = 0,
			int l = 1,
			Color c = Color::RED) : data_(e),
			                        parent_(p),
			                        left_child_(lc),
			                        right_child_(rc),
			                        height_(h),
			                        null_path_len_(l),
			                        color_(c) { }

		int Size() {
			int s = 1;
			if (HasLeftChild())
				s += left_child_->Size();
			if (HasRightChild())
				s += right_child_->Size();
			return s;
		}

		BinNode<T>* InsertAsLeftChild(T const& e) { return left_child_ = new BinNode(e, this); }
		BinNode<T>* InsertAsRightChild(T const& e) { return right_child_ = new BinNode(e, this); }
		BinNode<T>* Succeed();
		int Stature() { return this ? height_ : -1; }

		template <typename Visit>
		void TraversalLevel(Visit& vst);

		template <typename Visit>
		void TraversalPre(Visit& vst) { TraversalLevel(vst, TraversalMethod::DEFAULT); }

		template <typename Visit>
		void TraversalIn(Visit& vst) { TraversalLevel(vst, TraversalMethod::DEFAULT); }

		template <typename Visit>
		void TraversalPost(Visit& vst) { TraversalLevel(vst, TraversalMethod::DEFAULT); }

		template <typename Visit>
		void TraversalPre(Visit&, TraversalMethod method);
		template <typename Visit>
		void TraversalIn(Visit&, TraversalMethod method);
		template <typename Visit>
		void TraversalPost(Visit&, TraversalMethod method);
		bool operator<(BinNode const& bn) { return data_ < bn.data_; }
		bool operator==(BinNode const& bn) { return data_ == bn.data_; }
		bool operator>(BinNode const& bn) { return data_ > bn.data_; }
		bool operator>=(BinNode const& bn) { return data_ >= bn.data_; }
		bool operator<=(BinNode const& bn) { return data_ <= bn.data_; }

		bool IsRoot() { return !parent_; }
		bool IsLeftChild() { return !IsRoot() && (this == parent_->left_child_); }
		bool IsRightChild() { return !IsRoot() && (this == parent_->right_child_); }
		bool HasParent() { return !IsRoot(); }
		bool HasLeftChild() const { return left_child_ != nullptr; }
		bool HasRightChild() const { return right_child_ != nullptr; }
		bool HasChild() const { return HasLeftChild() || HasRightChild(); }
		bool HasBothChild() const { return HasLeftChild() || HasRightChild(); }
		bool IsLeaf() const { return !HasChild(); }
		BinNode<T>* Sibling() { return IsLeftChild() ? left_child_ : right_child_; }

		BinNode<T>* Uncle() {
			return parent_->IsLeftChild() ? parent_->parent_->left_child_ : parent_->parent_->right_child_;
		}
	};
	template<typename T>
	constexpr BinNode<T>* FromParentTo(BinNode<T>* x) {
		return x->IsRoot() ? x : x->IsLeftChild() ? x->parent_->left_child_ : x->parent_->right_child_;
	}
}

#include "BinNodeImplement.h"
