#pragma once
namespace simple_dsa
{
	template <typename T>
	void Vector<T>::Traverse(void (*visit)(T &))
	{
		for (int i = 0; i < size_; i++)
			visit(elem_[i]);
	}

	template <typename T>
	template <typename Visit>
	void Vector<T>::Traverse(Visit &visit)
	{
		for (int i = 0; i < size_; i++)
			visit(elem_[i]);
	}
}
