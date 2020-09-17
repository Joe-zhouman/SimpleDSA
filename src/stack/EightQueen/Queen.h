#pragma once
#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <iostream>
class Queen {
    int size_;

public:
    int x_;
    int y_;
    Queen(int x = 0, int y = 0) : x_(x), y_(y){};
    bool operator==(Queen const& q) const {
        if (x_ == q.x_) return true;
        if (x_ - q.x_ == y_ - q.y_) return true;
        if (x_ - q.y_ == q.x_ - y_) return true;
        if (y_ == q.y_) return true;
        return false;
    }
    bool operator!=(Queen const& q) const { return !(*this == q); }
    void SetSize(int n) { size_ = n; }
    void Dispaly() {
        std::cout << y_ << " ";
        for (auto i = 0; i < x_; i++) std::cout << 'O';
        std::cout << 'X';
        for (auto i = x_ + 1; i < size_; i++) std::cout << 'O';
        std::cout << std::endl;
    }
};
#endif  //_QUEEN_H_