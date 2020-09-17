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
namespace simple_dsa {

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
		Stack<BinNode<T>*> s;
		if (!x)
			s.push(x);
		while (s.empty()) {
			if (s.top() != x->parent_)
				GoStart<T>(s);
			x = s.Pop();
			vst(x->data_);
		}
	}

	template <typename T>
	template <typename Visit>
	void BinNode<T>::GoStart(Stack<BinNode<T>*>& s) {
		while (BinNode<T>* x = s.top()) {
			if (x->HasLeftChild()) {
				if (x->HasRightChild())
					s.push(x->right_child_);
				s.push(x->left_child_);
			}
			else
				s.push(x->right_child_);
		}
		s.Pop();
	}
}
