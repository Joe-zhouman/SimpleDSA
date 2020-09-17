#pragma once
#ifndef _MAZE_H_
#define _MAZE_H_
#include "MazeInfo.h"
class Maze {
    int size_;

public:
    simple_dsa::Vector<Cell> maze_;
    Maze(int n) { size_ = n; }
    void Init();
};
#endif //_MAZE_H_