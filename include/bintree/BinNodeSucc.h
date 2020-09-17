// Administrator
// DataStructure
// BinTree
// 2020-08-10-22:52
// *Author*    : Joe, Zhou Man 
// *Email*     : man.man.man.man.a@gmail.com 
// *Email*     : joe_zhouman@foxmail.com 
// *QQ*        : 1592020915 
// *Weibo*     : @zhouman_LFC 
// *Twitter*   : @zhouman_LFC 
// *Website*   : www.joezhouman.com 
// *Github*    : https://github.com/Joe-zhouman 
// *LeetCode*  : https://leetcode-cn.com/u/joe_zm/
#pragma once
namespace my_dsa {
	template <typename T>
	BinNode<T>* BinNode<T>::Succeed() {
		BinNode<T>* s_node = this;
		if (s_node->HasRightChild()) {
			s_node = s_node->right_child_;
			while (s_node->HasLeftChild()) {
				s_node = s_node->left_child_;
			}
		}
		else {
			while (s_node->IsRightChild()) {
				s_node = s_node->parent_;
			}
			s_node = s_node->parent_;
		}
		return s_node;
	}
}
