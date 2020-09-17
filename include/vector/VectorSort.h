#pragma once
namespace simple_dsa
{
	template <typename T>
	void Vector<T>::Sort(Rank lo, Rank hi, SortMethod method)
	{
		switch (method)
		{
		case SortMethod::BUBBLE:
			BubbleSort(lo, hi);
			break;
		case SortMethod::SELECTION:
			break;
		case SortMethod::MERGE:
			MergeSort(lo, hi);
			break;
		default:
			throw "error sort method!";
		}
	}
	template <typename T>
	void Vector<T>::Unsort(Rank lo, Rank hi)
	{
		T *V = elem_ + lo;
		for (Rank i = hi - lo; i > 0; i--)
			std::swap(V[i - 1], V[std::rand() % i]);
	}
} // namespace simple_dsa
