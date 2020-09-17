//
// Created by Joe.ZM on 2020/8/12.
//
#pragma once
#ifndef DATASTRUCTURE_GRAPH_EDGE_H_
#define DATASTRUCTURE_GRAPH_EDGE_H_

#include "GraphEnum.h"

namespace simple_dsa {

template <typename Te>
class Edge {
public:
    Te data_;
    int weight_;
    EType type_;
    Edge(Te const& d, int w)
        : data_(d), weight_(w), type_(EType::UNDETERMINED) {}
};
}  // namespace simple_dsa
#endif  // DATASTRUCTURE_GRAPH_EDGE_H_