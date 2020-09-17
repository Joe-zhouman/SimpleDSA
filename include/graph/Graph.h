// Joe
// 周漫
// 2020081219:47


#pragma once
#ifndef DATASTRUCTURE_GRAPH_GRAPH_H_
#define DATASTRUCTURE_GRAPH_GRAPH_H_

#include "GraphEnum.h"
#include <stack>
#include <queue>

namespace my_dsa {


    template<typename Tv, typename Te>
    class Graph {
        void Reset() {
            for (auto i = 0; i < v_; ++i) {
                Status(i) = VStatusEnum::UNDISCOVERED;
                DTime(i) = FTime(i) = -1;
                Parent(i) = -1;
                Priority(i) = INT_MAX;
                for (auto j = 0; j < v_; ++j) {
                    if (Exist(i, j))
                        Type(i, j) = ETypeEnum::UNDETERMINED;
                }
            }
        }
        void bfs(int, int&);
        void dfs(int, int&);
        void bcc(int, int&, std::stack<int>&);
        bool t_sort(int, int&, std::stack<Tv>*);
        template<typename Pu>
        void pfs(int, Pu);
    public:
        virtual ~Graph() = default;
        int v_;
        virtual int Insert(Tv const&) = 0;
        virtual Tv Remove(int) = 0;
        virtual Tv& VertexData(int) = 0;
        virtual int InDegree(int) = 0;
        virtual int OutDegree(int) = 0;
        virtual int FirstNbr(int) = 0;
        virtual int NextNbr(int, int) = 0;
        virtual VStatusEnum& Status(int) = 0;
        virtual int& DTime(int) = 0;
        virtual int& FTime(int) = 0;
        virtual int& Parent(int) = 0;
        virtual int& Priority(int) = 0;

        int e_;
        virtual bool Exist(int, int) = 0;
        virtual void Insert(Te const&, int, int, int) = 0;
        virtual Te Remove(int, int) = 0;
        virtual ETypeEnum& Type(int, int) = 0;
        virtual Te& EdgeData(int, int) = 0;
        virtual int& Weight(int, int) = 0;

        void BFS(int);
        void DFS(int);
        std::stack<Tv>* TSort(int);
        void BCC(int);
        void Prim(int);
        void Dijkstra(int);
        template<typename Pu>
        void PFS(int, Pu);
    };
}
#include "GraphImplement.h"
#endif //DATASTRUCTURE_GRAPH_GRAPH_H_