// Joe
// 周漫
// 2020081910:43


#pragma once
namespace my_dsa {

	template<typename Tv, typename Te>
	struct PrimPU {
		virtual void operator()(Graph<Tv, Te>* g, int uk, int v) {
			if (g->Status(v) == ETypeEnum::UNDETERMINED) {
				if (g->Priority(v) > g->Weight(uk, v)) {
					g->Priority(v) = g->Weight(uk, v);
					g->Parent(v) = uk;
				}
			}
		}
	};
}
