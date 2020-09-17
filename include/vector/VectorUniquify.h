#pragma once
namespace simple_dsa
{
	template <typename T>
	int Vector<T>::Uniquify()
	{
		Rank i = 0, j = 0;
		while (++j < size_)
		{
			if (elem_[i] != elem_[j])
				elem_[++i] = elem_[j];
		}
		size_ = ++i;
		Shrink();
		return j - i;
	}
}