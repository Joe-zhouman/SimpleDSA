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
	BinNodePosi<T> BinTree<T>::AttachAsRightChild(BinNodePosi<T> x, BinTree<T>*& t) {
		if (x->right_child_ = t->root_)
			x->right_child_->parent_ = x;
		size_ += t->size_;
		UpdateHeightAbove(x);
		t->root_ = nullptr;
		t->size_ = 0;
		release(t);
		t = nullptr;
		return x;
	}

	template <typename T>
	BinNodePosi<T> BinTree<T>::AttachAsLeftChild(BinNodePosi<T> x, BinTree<T>*& t) {
		if (x->left_child_ = t->root_)
			x->left_child_->parent_ = x;
		size_ += t->size_;
		UpdateHeightAbove(x);
		t->root_ = nullptr;
		t->size_ = 0;
		release(t);
		t = nullptr;
		return x;
	}
}
