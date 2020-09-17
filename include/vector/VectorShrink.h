#pragma once
namespace simple_dsa
{
	template <typename T>
	void Vector<T>::Shrink()
	{
		if (capacity_ < kDefaultCapacity << 1)
			return;
		if (size_ << 2 > capacity_)
			return;
		T *oldElem = elem_;
		elem_ = new T[capacity_ >>= 1];
		for (int i = 0; i < size_; i++)
			elem_[i] = oldElem[i];
		delete oldElem;
	}
}