// Joe
// 周漫
// 2020081816:19

#pragma once
namespace simple_dsa {

template <typename Tv, typename Te>
Stack<Tv>* Graph<Tv, Te>::TSort(int s) {
    Reset();
    int clock = 0;
    int v = s;
    auto* rcd_s = new Stack<Tv>;
    do {
        if (Status(v) == VStatus::UNDISCOVERED) {
            if (!t_sort(v, clock, rcd_s)) {
                while (!rcd_s->empty()) {
                    rcd_s->Pop();
                    break;
                }
            }
        }
    } while (s != (v = (++v % v_)));
    return rcd_s;
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::t_sort(int v, int& clock, Stack<Tv>* s) {
    DTime(v) = ++clock;
    Status(v) = VStatus::DISCOVERED;
    for (int u = FirstNbr(v); - 1 < u; u = NextNbr(v, u)) {
        switch (Status(u)) {
            case VStatus::UNDISCOVERED:
                Parent(u) = v;
                Type(v, u) = EType::TREE;
                if (!t_sort(u, clock, s)) {
                    return false;
                }
                break;
            case VStatus::DISCOVERED:
                Type(v, u) = EType::BACKWARD;
                return false;
            default:
                Type(v, u) =
                    (DTime(v) < DTime(u)) ? EType::FORWARD : EType::CROSS;
                break;
        }
    }
    Status(v) = VStatus::VISITED;
    s->push(VertexData(v));
    return true;
}
}  // namespace simple_dsa