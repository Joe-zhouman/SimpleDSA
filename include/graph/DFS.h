// Joe
// 周漫
// 2020081722:36


#pragma once
namespace my_dsa {

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
		Status(v) = VStatusEnum::DISCOVERED;
		for (int u = FirstNbr(v); -1 < u; u = NextNbr(v, u)) {
			switch (Status(u)) {
			case VStatusEnum::UNDISCOVERED:
			{
				Type(v, u) = ETypeEnum::TREE;
				Parent(u) = v;
				dfs(u, clock);
				break;
			}
			case VStatusEnum::DISCOVERED:
			{
				Type(v, u) = ETypeEnum::BACKWARD;
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
		FTime(v) = ++clock;
	}
}