#pragma once
namespace simple_dsa
{
	template <typename T>
	Rank Vector<T>::Insert(Rank r, T const &e)
	{
		Expand();
		for (int i = size_; i > r; i--)
		{
			elem_[i] = elem_[i - 1];
		}
		elem_[r] = e;
		size_++;
		return r;
	}
}
