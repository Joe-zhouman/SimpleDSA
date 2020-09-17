// Joe
// 周漫
// 2020081816:19


#pragma once
namespace my_dsa {

	template <typename Tv, typename Te>
	std::stack<Tv>* Graph<Tv, Te>::TSort(int s) {
		Reset();
		int clock = 0;
		int v = s;
		auto* rcd_s = new std::stack<Tv>;
		do {
			if (Status(v) == VStatusEnum::UNDISCOVERED) {
				if (!t_sort(v, clock, rcd_s)) {
					while (!rcd_s->empty()) {
						rcd_s->pop();
						break;
					}

				}
			}
		} while (s != (v = (++v % v_)));
		return rcd_s;
	}

	template <typename Tv, typename Te>
	bool Graph<Tv, Te>::t_sort(int v, int& clock, std::stack<Tv>* s) {
		DTime(v) = ++clock;
		Status(v) = VStatusEnum::DISCOVERED;
		for (int u = FirstNbr(v); -1 < u; u = NextNbr(v, u)) {
			switch (Status(u)) {
			case VStatusEnum::UNDISCOVERED:
				Parent(u) = v;
				Type(v, u) = ETypeEnum::TREE;
				if (!t_sort(u, clock, s)) {
					return false;
				}
				break;
			case VStatusEnum::DISCOVERED:
				Type(v, u) = ETypeEnum::BACKWARD;
				return false;
			default:
				Type(v, u) = (DTime(v) < DTime(u)) ? ETypeEnum::FORWARD : ETypeEnum::CROSS;
				break;
			}
		}
		Status(v) = VStatusEnum::VISITED;
		s->push(VertexData(v));
		return true;
	}
}