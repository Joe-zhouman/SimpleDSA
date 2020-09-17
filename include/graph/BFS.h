// Joe
// 周漫
// 2020081722:15


#pragma once
namespace my_dsa {

	template <typename Tv, typename Te>
	void Graph<Tv, Te>::BFS(int s) {
		Reset();
		int clock = 0;
		int v = s;
		do {
			if (Status(v) == VStatusEnum::UNDISCOVERED)
				bfs(v, clock);
		} while (s != (v = ++v % v_));
	}

	template <typename Tv, typename Te>
	void Graph<Tv, Te>::bfs(int v, int& clock) {
		std::queue<int> q;
		Status(v) = VStatusEnum::DISCOVERED;
		q.push(v);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			DTime(v) = ++clock;
			for (int u = FirstNbr(v); -1 < u; u = NextNbr(v, u)) {
				if (Status(u) == VStatusEnum::UNDISCOVERED) {
					Status(u) = VStatusEnum::DISCOVERED;
					q.push(u);
					Type(v, u) = ETypeEnum::TREE;
					Parent(u) = v;
				}
				else {
					Type(v, u) = ETypeEnum::CROSS;
				}
			}
			Status(v) = VStatusEnum::VISITED;
		}
	}
}