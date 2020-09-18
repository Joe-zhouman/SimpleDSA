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
	static int RemoveAt(BinNodePosi<T> x) {
		if (!x)
			return 0;
		int n = 1 + RemoveAt(x->left_child_) + RemoveAt(x->right_child_);
		release(x->data_);
		release(x);
		return n;
	};

	template <typename T>
	int BinTree<T>::Remove(BinNodePosi<T> x) {
		FromParentTo(x) = nullptr;
		UpdateHeightAbove(x->parent_);
		const int n = RemoveAt(x);
		size_ -= n;
		return n;
	}

	template <typename T>
	BinTree<T>* BinTree<T>::Secede(BinNodePosi<T> x) {
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
