#pragma once
namespace simple_dsa
{
	template <typename T>
	T &Vector<T>::operator[](Rank r)
	{
		if (r < size_ && r >= 0)
			return elem_[r];
		throw("rank out of range");
	};

	template <typename T>
	const T &Vector<T>::operator[](Rank r) const
	{
		if (r < size_ && r >= 0)
			return elem_[r];
		throw("rank out of range");
	};
}