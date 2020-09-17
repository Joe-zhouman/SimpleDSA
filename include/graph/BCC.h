// Joe
// 周漫
// 2020081817:40


#pragma once
namespace my_dsa {

	template <typename Tv, typename Te>
	void Graph<Tv, Te>::BCC(int s) {
		Reset();
		int clock = 0;
		int v = s;
		std::stack<int> rcd_s;
		do {
			if (Status(v) == VStatusEnum::UNDISCOVERED) {
				bcc(v, clock, rcd_s);
				rcd_s.pop();
			}
		} while (s != (v = (++v % v_)));
	}
	template <typename Tv, typename Te>
	constexpr int hca(int x) { return  Graph<Te, Tv>::FTime(x); }
	template <typename Tv, typename Te>
	void Graph<Tv, Te>::bcc(int v, int& clock, std::stack<int>& s) {
		hca<Tv, Te>(v) = DTime(v) = ++clock;
		Status(v) = VStatusEnum::DISCOVERED;
		s.push(v);
		for (auto u = FirstNbr(v); -1 < u; u = NextNbr(v, u)) {
			switch (Status(u)) {
			case VStatusEnum::UNDISCOVERED:
			{
				Parent(u) = v;
				Type(v, u) = ETypeEnum::TREE;
				bcc(u, clock, s);
				if (hca<Tv, Te>(u) < DTime(v)) {
					hca<Tv, Te>(v) = std::min(hca<Tv, Te>(v), hca<Tv, Te>(u));
				}
				else {
					while (v != s.top()) {
						s.pop();
						s.push(v);
					}
					s.pop();
				}
			}
			case VStatusEnum::DISCOVERED:
			{
				Type(v, u) = ETypeEnum::BACKWARD;
				if (u != Parent(v))
					hca<Tv, Te>(v) = std::min(hca<Tv, Te>(v), hca<Tv, Te>(u));
				break;
			}
			default:
			{
				Type(v, u) = (DTime(v) < DTime(u)) ? ETypeEnum::FORWARD : ETypeEnum::CROSS;
				break;
			}
			}
		}
		Status(v) = VStatusEnum::VISITED;
	}

}