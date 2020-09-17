// Joe
// 周漫
// 2020081817:40

#pragma once
namespace simple_dsa {

template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int s) {
    Reset();
    int clock = 0;
    int v = s;
    Stack<int> rcd_s;
    do {
        if (Status(v) == VStatus::UNDISCOVERED) {
            bcc(v, clock, rcd_s);
            rcd_s.Pop();
        }
    } while (s != (v = (++v % v_)));
}
template <typename Tv, typename Te>
constexpr int hca(int x) {
    return Graph<Te, Tv>::FTime(x);
}
template <typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int v, int& clock, Stack<int>& s) {
    hca<Tv, Te>(v) = DTime(v) = ++clock;
    Status(v) = VStatus::DISCOVERED;
    s.push(v);
    for (auto u = FirstNbr(v); - 1 < u; u = NextNbr(v, u)) {
        switch (Status(u)) {
            case VStatus::UNDISCOVERED: {
                Parent(u) = v;
                Type(v, u) = EType::TREE;
                bcc(u, clock, s);
                if (hca<Tv, Te>(u) < DTime(v)) {
                    hca<Tv, Te>(v) = std::min(hca<Tv, Te>(v), hca<Tv, Te>(u));
                } else {
                    while (v != s.Pop()) {
                        s.push(v);
                    }
                    s.Pop();
                }
            }
            case VStatus::DISCOVERED: {
                Type(v, u) = EType::BACKWARD;
                if (u != Parent(v))
                    hca<Tv, Te>(v) = std::min(hca<Tv, Te>(v), hca<Tv, Te>(u));
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
}

}  // namespace simple_dsa