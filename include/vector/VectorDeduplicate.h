#pragma once
namespace simple_dsa
{
	template <typename T>
	int Vector<T>::Deduplicate()
	{
		const int oldSize = size_;
		Rank i = 1;
		while (i < size_)
		{
			(Find(elem_[i], 0, i)) ? i++ : Remove(i);
		}
		return oldSize - size_;
	}
}