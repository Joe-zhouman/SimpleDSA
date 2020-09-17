/*********************SimpleDSA************************/
/*    A simple implemention of `data structure and    */
/*  algorithm` in Cpp form                            */
/*********************About Me*************************/
/* *Author*     : Joe, Zhou Man                       */
/* *Email*      : man.man.man.man.a@gmail.com         */
/* *Email*      : joe_zhouman@foxmail.com             */
/* *QQ*         : 1592020915                          */
/* *Weibo*      : @zhouman_LFC                        */
/* *Twitter*    : @zhouman_LFC                        */
/* *Tiktok*     : @JOE.ZM                             */
/* *Website*    : www.joezhouman.com                  */
/* *Github*     : https://github.com/Joe-zhouman      */
/* *LeetCode*   : https://leetcode-cn.com/u/joe_zm/   */
/* *Bilibili*   : https://space.bilibili.com/2743678  */
/******************************************************/
/*                  不务正业的科研狗                     */
/*            You'll never walk alone                 */
/******************************************************/
#pragma once
#include "BinNode.h"
#include "MethodEnum.h"
#include "../_share/release.h"

namespace simple_dsa {

	template <typename T>
	class BinTree {
	protected:
		int size_;
		BinNode<T>* root_;
		virtual int UpdateHeight(BinNode<T>* x);
		void UpdateHeightAbove(BinNode<T>* x);
	public:
		BinTree() : size_(0),
		            root_(nullptr) { }

		~BinTree() {
			if (0 < size_)
				Remove(root_);
		}

		int Size() const { return size_; }
		bool Empty() const { return !root_; }
		BinNode<T>* Root() const { return root_; }
		BinNode<T>* InsertAsRoot(T const& e);
		BinNode<T>* InsertAsLeftChild(BinNode<T>*, T const&);
		BinNode<T>* InsertAsRightChild(BinNode<T>*, T const&);
		BinNode<T>* AttachAsLeftChild(BinNode<T>* x, BinTree<T>*& t);
		BinNode<T>* AttachAsRightChild(BinNode<T>* x, BinTree<T>*& t);
		int Remove(BinNode<T>* x);
		BinTree<T>* Secede(BinNode<T>* x);

		template <typename Visit>
		void TraversalLevel(Visit& visit) {
			if (root_ != nullptr)
				root_->TraversalLevel(visit);
		}

		template <typename Visit>
		void TraversalPre(Visit& visit, TraversalMethod method) {
			if (root_)
				root_->TraversalPre(visit, method);
		}

		template <typename Visit>
		void TraversalPre(Visit& visit) {
			TraversalPre(visit, TraversalMethod::DEFAULT);
		}

		template <typename Visit>
		void TraversalIn(Visit& visit, TraversalMethod method) {
			if (root_)
				root_->TraversalIn(visit, method);
		}

		template <typename Visit>
		void TraversalIn(Visit& visit) {
			TraversalIn(visit, TraversalMethod::DEFAULT);
		}

		template <typename Visit>
		void TraversalPost(Visit& visit, TraversalMethod method) {
			if (root_)
				root_->TraversalPost(visit, method);
		}

		template <typename Visit>
		void TraversalPost(Visit& visit) {
			TraversalPost(visit, TraversalMethod::DEFAULT);
		}

		bool operator<(BinTree<T> const& t) { return root_ && t.root_ && root_ < t.root_; }
		bool operator<=(BinTree<T> const& t) { return root_ && t.root_ && root_ <= t.root_; }
		bool operator==(BinTree<T> const& t) { return root_ && t.root_ && root_ == t.root_; }
		bool operator>(BinTree<T> const& t) { return root_ && t.root_ && root_ > t.root_; }
		bool operator>=(BinTree<T> const& t) { return root_ && t.root_ && root_ >= t.root_; }

	};
}

#include "BinTreeImplement.h"
