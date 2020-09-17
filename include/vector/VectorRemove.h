#pragma once
namespace simple_dsa
{
	template <typename T>
	int Vector<T>::Remove(Rank lo, Rank hi)
	{
		if (lo == hi)
			return 0;
		while (hi < size_)
			elem_[lo++] = elem_[hi++];
		size_ = lo;
		Shrink();
		return hi - lo;
	}

	template <typename T>
	T Vector<T>::Remove(Rank r)
	{
		T e = elem_[r];
		Remove(r, r + 1);
		return e;
	}
}
