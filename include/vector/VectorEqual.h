#pragma once
#ifndef _VECTOR_EQUAL_H_
#define _VECTOR_EQUAL_H_
namespace simple_dsa
{
	template <typename T>
	Vector<T>& Vector<T>::operator=(Vector<T> const& oldVector) {
		if (elem_)
			delete[] elem_;
		CopyFrom(oldVector.elem_, 0, oldVector.Size());
		return *this;
	}
}
#endif //_VECTOR_EQUAL_H_


