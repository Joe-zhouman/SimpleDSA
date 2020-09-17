//
// Created by Joe.ZM on 2020/8/12.
//
#pragma once
#ifndef DATASTRUCTURE_GRAPH_EDGE_H_
#define DATASTRUCTURE_GRAPH_EDGE_H_


#include "GraphEnum.h"

namespace my_dsa {

	template <typename Te> class Edge {
	public:
		Te data_;
		int weight_;
		ETypeEnum type_;
		Edge(Te const& d, int w) :
			data_(d),
			weight_(w),
			type_(ETypeEnum::UNDETERMINED) {
		}
	};
}
#endif //DATASTRUCTURE_GRAPH_EDGE_H_