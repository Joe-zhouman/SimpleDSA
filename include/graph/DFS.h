// Joe
// 周漫
// 2020081722:36

#pragma once
namespace simple_dsa {

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int s) {
    Reset();
    int clock = 0;
    int v = s;
    do {
        dfs(v, clock);
    } while (s != (v = (++v % v_)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int v, int& clock) {
    DTime(v) = ++clock;
    Status(v) = VStatus::DISCOVERED;
    for (int u = FirstNbr(v); - 1 < u; u = NextNbr(v, u)) {
        switch (Status(u)) {
            case VStatus::UNDISCOVERED: {
                Type(v, u) = EType::TREE;
                Parent(u) = v;
                dfs(u, clock);
                break;
            }
            case VStatus::DISCOVERED: {
                Type(v, u) = EType::BACKWARD;
                break;
            }
            default: {
                Type(v, u) =
                    (DTime(v) < DTime(u)) ? EType::FORWARD : EType::CROSS;
                break;
            }
        }
    }
    Status(v) = VStatus::VISITED;
    FTime(v) = ++clock;
}
}  // namespace simple_dsa