//
// Created by Administrator on 2020/8/12.
//
#pragma once
#ifndef DATASTRUCTURE_GRAPH_VERTEX_H_
#define DATASTRUCTURE_GRAPH_VERTEX_H_

#include "GraphEnum.h"

namespace simple_dsa {

template <typename Tv>
class Vertex {
public:
    Tv data_;
    int in_degree_, out_degree_;
    VStatus status_;
    int d_time_, f_time_;
    int parent_;
    int priority_;
    Vertex(Tv const& d = static_cast<Tv>(0))
        : data_(d),
          in_degree_(0),
          out_degree_(0),
          status_(VStatus::UNDISCOVERED),
          d_time_(-1),
          f_time_(-1),
          parent_(-1),
          priority_(INT_MAX) {}
};
}  // namespace simple_dsa
#endif  // DATASTRUCTURE_GRAPH_VERTEX_H_