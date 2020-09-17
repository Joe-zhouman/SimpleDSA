#pragma once
#ifndef _MAZE_INFO_H_
#define _MAZE_INFO_H_
#include <vector/Vector.h>

enum class Status { AVAILABLE, ROUTE, BACKTRACKED, WALL };

enum class Direction { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY };

inline Direction NextDirection(Direction dir) {
    return static_cast<Direction>(static_cast<int>(dir) + 1);
}

class Cell {
public:
    int x_;
    int y_;
    Status status_;
    Direction in_;
    Direction out_;
    Cell(int x, int y,Status status = Status::AVAILABLE){
        x_ = x;
        y_ = y;
        status_ = status;
        in_ = Direction::UNKNOWN;
        out_ = Direction::UNKNOWN;
    }
};

#endif  //_MAZE_INFO_H_