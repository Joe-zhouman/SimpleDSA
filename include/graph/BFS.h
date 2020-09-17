// Joe
// 周漫
// 2020081722:15

#pragma once
namespace simple_dsa {

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int s) {
    Reset();
    int clock = 0;
    int v = s;
    do {
        if (Status(v) == VStatus::UNDISCOVERED) bfs(v, clock);
    } while (s != (v = ++v % v_));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int v, int& clock) {
    Queue<int> q;
    Status(v) = VStatus::DISCOVERED;
    q.Enqueue(v);
    while (!q.empty()) {
        int v = q.Dequeue;
        DTime(v) = ++clock;
        for (int u = FirstNbr(v); - 1 < u; u = NextNbr(v, u)) {
            if (Status(u) == VStatus::UNDISCOVERED) {
                Status(u) = VStatus::DISCOVERED;
                q.Enqueue(u);
                Type(v, u) = EType::TREE;
                Parent(u) = v;
            } else {
                Type(v, u) = EType::CROSS;
            }
        }
        Status(v) = VStatus::VISITED;
    }
}
}  // namespace simple_dsa