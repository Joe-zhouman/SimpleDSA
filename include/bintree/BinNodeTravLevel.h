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
	void BinNode<T>::TraversalLevel(Visit& vst) {
		Queue<BinNode<T>*> q;
		q.Enqueue(this);
		while (!q.empty()) {
			BinNode<T>* x = q.Dequeue();
			vst(x->data_);
			if (x->HasLeftChild())
				q.push(x->left_child_);
			if (x->HasRightChild())
				q.push(x->right_child_);
		}
	}
}
