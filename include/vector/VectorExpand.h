#pragma once
namespace simple_dsa
{
	template <typename T>
	void Vector<T>::Expand()
	{
		if (size_ < capacity_)
			return;
		if (capacity_ < kDefaultCapacity)
			capacity_ = kDefaultCapacity;
		T *oldElem = elem_;
		elem_ = new T[capacity_ <<= 1];
		for (int i = 0; i < size_; i++)
		{
			elem_[i] = oldElem[i];
		}
		delete oldElem;
	}
}