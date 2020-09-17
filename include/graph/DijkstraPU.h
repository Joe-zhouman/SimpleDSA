// Joe
// 周漫
// 2020081910:59


#pragma once
namespace my_dsa {

	template<typename Tv, typename Te>
	struct DijkstraPU {
		virtual void operator()(Graph<Tv, Te>* g, int uk, int v) {
			if (g->Status(v) == VStatusEnum::UNDISCOVERED) {
				if (g->Priority(v) > g->Priority(uk) + g->Weight(uk, v)) {
					g->Priority(v) = g->Priority(uk) + g->Weight(uk, v);
					g->Parent(v) = uk;
				}
			}
		}

	};
}