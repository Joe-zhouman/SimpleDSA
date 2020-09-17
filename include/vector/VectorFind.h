#pragma once
namespace simple_dsa {
template <typename T>
Rank Vector<T>::Find(T const &e, Rank lo, Rank hi) const {
    while ((lo < hi--) && e != elem_[hi]) {
    }
    return hi;
}
}  // namespace simple_dsa