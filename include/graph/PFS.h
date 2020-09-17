// Joe
// 周漫
// 202008199:59


#pragma once
namespace my_dsa {

	template <typename Tv, typename Te>
	template <typename Pu>
	void Graph<Tv, Te>::PFS(int s, Pu priority_updater) {
		Reset();
		int v = s;
		do {
			if (Status(v) == VStatusEnum::UNDISCOVERED)
				pfs(v, priority_updater);
		} while (s != (v = (++v % v_)));
	}
	template <typename Tv, typename Te>
	template <typename Pu>
	void Graph<Tv, Te>::pfs(int s, Pu priority_updater) {
		Priority(s) = 0;
		Status(s) = VStatusEnum::VISITED;
		Parent(s) = -1;
		while (true) {
			for (int w = FirstNbr(s); -1 < w; w = NextNbr(s, w))
				priority_updater(this, s, w);
			for (auto shortest = INT_MAX, w = 0; w < v_; w++) {
				if (Status(w) == VStatusEnum::UNDISCOVERED)
					if (shortest > Priority(w)) {
						shortest = Priority(w);
						s = w;
					}
			}
			if (Status(s) == VStatusEnum::VISITED)
				break;
			Status(s) = VStatusEnum::VISITED;
			Type(Parent(s), s) = ETypeEnum::TREE;
		}
	}
}