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
#ifndef _BITMAP_H_
#define _BITMAP_H_

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>

#include <iostream>
namespace simple_dsa {
class Bitmap {
private:
    char* bits_;
    int size_;

protected:
    void Init(int n) {
        bits_ = new char[size_ = (n + 7) / 8];
        memset(bits_, 0, size_);
    }
    void Expand(int k) {
#ifdef __STDC_LIB_EXT1__
        if (k < 8 * size_) return;
        int old_size = size_;
        char* old_bits = bits_;
        Init(2 * k);
        memcpy_s(bits_, size_, old_bits, old_size);
        delete[] old_bits;
        return;
#endif
        std::cout << "Expand Failed" << std::endl;
        exit(-1);
    }

public:
    Bitmap(int n = 100) { Init(n); }
    Bitmap(char* file,int n = 100){
        Init(n);
        FILE* fp = fopen(file,"r");
        fread(bits_,sizeof(char),size_,fp);
        fclose(fp);
    }
    ~Bitmap() {
        delete[] bits_;
        bits_ = nullptr;
    }

    void Set(int k) {
        Expand(k);
        bits_[k >> 3] |= (0x80 >> (k & 0x07));
    }
    void Clear(int k) {
        Expand(k);
        bits_[k >> 3] &= ~(0x80 >> (k & 0x07));
    }
    bool Find(int k) {
        Expand(k);
        return bits_[k >> 3] & (0x80 >> (k & 0x07));
    }
    void Dump(char* file){
        FILE* fp = fopen(file,"w");
        fwrite(bits_,sizeof(char),size_,fp);
        fclose(fp);
    }
};

}  // namespace simple_dsa
#endif  //_BITMAP_H_