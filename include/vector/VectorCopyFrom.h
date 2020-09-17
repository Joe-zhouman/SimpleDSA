#pragma once
namespace simple_dsa
{
	template <typename T>
	void Vector<T>::CopyFrom(T const *copiedArray, Rank lo, Rank hi)
	{
		elem_ = new T[capacity_ = 2 * (hi - lo)];
		size_ = 0;
		while (lo < hi)
		{
			elem_[size_++] = copiedArray[lo++];
		}
	}
}