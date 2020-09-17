#pragma once
namespace simple_dsa
{
	template <typename T>
	static Rank BinSearch(T *S, T const &e, Rank lo, Rank hi);

	template <typename T>
	Rank Vector<T>::Search(T const &e, Rank lo, Rank hi, SearchMethod method) const
	{
		switch (method)
		{
		case SearchMethod::BINARY:
			return BinSearch(elem_, e, lo, hi);
		default :
			throw "error method type";
	}
}

//二分法搜索
template <typename T>
static Rank BinSearch(T* S, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		//每步迭代仅需做一次比较判断，有两个分支
		Rank mi = (lo + hi) >> 1;            //以中点为轴点（区间宽度的折半，等效于宽度之数值表示的右移）
		(e < S[mi]) ? hi = mi : lo = mi + 1; //经比较后确定深入[lo, mi)或(mi, hi)
	}                                        //成功查找不能提前终止
	return lo - 1;                           //循环结束时，lo为大于e的元素的最小秩，故lo - 1即不大于e的元素的最大秩
}      
}                                      //有多个命中元素时，总能保证返回秩最大者；查找失败时，能够返回失败的位置
