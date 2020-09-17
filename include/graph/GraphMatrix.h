//
// Created by Joe.ZM on 2020/8/12.
//
#pragma once
#ifndef DATASTRUCTURE_GRAPH_GRAPHMATRIX_H_
#define DATASTRUCTURE_GRAPH_GRAPHMATRIX_H_

#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "GraphEnum.h"
#include "Vertex.h"

namespace simple_dsa {

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
    std::vector<Vertex<Tv>> v_set_;
    std::vector<std::vector<Edge<Te>*>> e_set_;

public:
    GraphMatrix() {
        this->v_ = 0;
        this->e_ = 0;
    }

    ~GraphMatrix() override {
        for (int i = 0; i < this->v_; ++i) {
            for (int j = 0; j < this->v_; ++j) {
                delete e_set_[i][j];
            }
        }
    }

    Tv& VertexData(int i) override { return v_set_[i].data_; }

    int InDegree(int i) override { return v_set_[i].in_degree_; }

    int OutDegree(int i) override { return v_set_[i].out_degree_; }

    int FirstNbr(int i) override { return NextNbr(i, this->v_); }

    int NextNbr(int i, int j) override {
        while ((-1 < j) && (!this->Exist(i, --j)))
            ;
        return j;
    }

    VStatus& Status(int i) override { return v_set_[i].status_; }

    int& DTime(int i) override { return v_set_[i].d_time_; }
    int& FTime(int i) override { return v_set_[i].f_time_; }
    int& Parent(int i) override { return v_set_[i].parent_; }
    int& Priority(int i) override { return v_set_[i].priority_; }
    int Insert(Tv const& vertex) override {
        for (auto i = 0; i < this->v_; ++i) {
            e_set_[i].push_back(nullptr);
        }
        ++this->v_;
        e_set_.push_back(std::vector<Edge<Te>*>(this->v_));
        v_set_.push_back(Vertex<Tv>(vertex));
        return this->v_ - 1;
    }
    Tv Remove(int i) override {
        for (int j = 0; j < this->v_; ++j) {
            if (Exist(i, j)) {
                delete e_set_[i][j];
                --v_set_[i].in_degree_;
                --this->e_;
            }
        }
        e_set_.erase(e_set_.begin() + i);
        --this->v_;
        Tv v_bak = VertexData(i);
        v_set_.erase(v_set_.begin() + i);
        for (int j = 0; j < this->v_; ++j) {
            Edge<Te>* e = e_set_[j][i];
            if (e != nullptr) {
                e_set_[j].erase(e_set_[j].begin() + i);
                delete e;
                --v_set_[i].out_degree_;
                --this->e_;
            }
        }
        return v_bak;
    }
    bool Exist(int i, int j) override {
        return (0 <= i) && (i < this->v_) && (0 <= j) && (j < this->v_) &&
               e_set_[i][j] != nullptr;
    }
    void Insert(Te const& edge, int w, int i, int j) override {
        if (Exist(i, j)) return;
        e_set_[i][j] = new Edge<Te>(edge, w);
        ++this->e_;
        ++v_set_[i].out_degree_;
        ++v_set_[j].in_degree_;
    }
    Te Remove(int i, int j) override {
        Te e_bak = EdgeData(i, j);
        delete e_set_[i][j];
        e_set_[i][j] = nullptr;
        --this->e_;
        --v_set_[i].out_degree_;
        --v_set_[j].in_degree_;
        return e_bak;
    }
    EType& Type(int i, int j) override { return e_set_[i][j]->type_; }
    Te& EdgeData(int i, int j) override { return e_set_[i][j]->data_; }
    int& Weight(int i, int j) override { return e_set_[i][j]->data_; }
};
}  // namespace simple_dsa
#endif  // DATASTRUCTURE_GRAPH_GRAPHMATRIX_H_
