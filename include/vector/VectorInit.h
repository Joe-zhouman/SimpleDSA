#pragma once
#include <istream>
#if !defined(_VECTOR_INIT_H_)
#define _VECTOR_INIT_H_
namespace simple_dsa
{
    typedef int Rank;

    constexpr int kDefaultCapacity = 20;

    enum class SortMethod
    {
        BUBBLE,
        SELECTION,
        MERGE,
        HEAP,
        QUICK,
        SHELL,
        DEFAULT = QUICK
    };

    enum class SearchMethod
    {
        BINARY,
        FIBONACCIAN,
        DEFAULT = BINARY
    };
} // namespace simple_dsa
#endif // _VECTOR_INIT_H_
