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
#ifndef _ENTRY_H_
#define _ENTRY_H_
namespace simple_dsa {
template <typename K, typename V>
class Entry {
public:
    K key_;
    V value_;
    Entry(K k = K(), V v = V()) : key_(k), value_(v){};
    Entry(Entry<K, V> const& e) : key_(e.key_), value_(e.value_){};
    bool operator<(Entry<K, V> const& e) { return key_ < e.key_; }
    bool operator>(Entry<K, V> const& e) { return key_ > e.key_; }
    bool operator==(Entry<K, V> const& e) { return key_ == e.key_; }
    bool operator!=(Entry<K, V> const& e) { return key_ != e.key_; }
};
}  // namespace simple_dsa
#endif  //_ENTRY_H_