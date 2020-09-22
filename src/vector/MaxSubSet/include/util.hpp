#pragma once
#ifndef _UTIL_HPP_
#define _UTIL_HPP_

template <typename T>
void PrintVector(Vector<T> vec) {
    std::cout << "vec[" << vec.Size() << "]={";

    for (size_t i = 0; i < vec.Size() - 1; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.Size() - 1] << '}' << std::endl;
}
#endif  //_UTIL_HPP_
