#pragma once
#ifndef _EIGHT_QUEEN_H_
#define _EIGHT_QUEEN_H_
#include <stack/Stack.h>

#include <iostream>
#include <string>

#include "Queen.h"
class EightQueens {
private:
    simple_dsa::Stack<Queen> queens_;
    int size_;
    int n_sln_;

public:
    EightQueens(int n);
    void PlaceQueens();
    void ShowQueens();
    bool HasSolution() { return 0 < n_sln_; }
};

EightQueens::EightQueens(int n) { size_ = n; }

void EightQueens::PlaceQueens() {
    Queen q(0, 0);
    q.SetSize(size_);
    do {
        if (size_ <= queens_.Size() || size_ <= q.x_) {
            q = queens_.Pop();
            q.x_++;
        } else {
            while ((q.x_ < size_) && (0 <= queens_.Find(q))) {
                q.x_++;
            }
            if (q.x_ < size_) {
                queens_.Push(q);
                if (size_ <= queens_.Size()) {
                    n_sln_++;
                    ShowQueens();
                }
                q.y_++;
                q.x_ = 0;
            }
        }
    } while (0 < q.y_ || q.x_ < size_);
}
void EightQueens::ShowQueens() {
    auto queens = queens_;
    std::cout << "Solution " << n_sln_ << " :" << std::endl << std::endl;
    while (!(queens.Empty())) {
        queens.Pop().Dispaly();
    }
    std::cout << "  ";
    for (size_t i = 0; i < size_; i++) {
        std::cout << " ";
    }
    std::cout<<std::endl;
    std::cout << "  ";
    for (size_t i = 0; i < size_; i++) {
        std::cout << static_cast<char>(('A' + i));
    }
    std::cout << std::endl << std::endl;
}
#endif  //_EIGHT_QUEEN_H_