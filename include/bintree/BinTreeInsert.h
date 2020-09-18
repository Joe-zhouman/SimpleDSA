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
	BinNodePosi<T> BinTree<T>::InsertAsRoot(T const& e) {
		size_ = 1;
		return root_ = new BinNode<T>(e);
	}

	template <typename T>
	BinNodePosi<T> BinTree<T>::InsertAsLeftChild(BinNodePosi<T> x, T const& e) {
		size_++;
		x->InsertAsLeftChild(e);
		UpdateHeightAbove(x);
		return x->left_child_;
	}

	template <typename T>
	BinNodePosi<T> BinTree<T>::InsertAsRightChild(BinNodePosi<T> x, T const& e) {
		size_++;
		x->InsertAsRightChild(e);
		UpdateHeightAbove(x);
		return x->right_child_;
	}
}
