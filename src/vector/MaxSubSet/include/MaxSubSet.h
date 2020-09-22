#pragma once
#ifndef _MAX_SUB_SET_H_
#define _MAX_SUB_SET_H_

#include <vector/Vector.h>
using namespace simple_dsa;

constexpr int lb = -1000;
constexpr int ub = 1000;

template <typename T>
struct TradeInfo {
    T profit_;
    int buying_day_;
    int saling_day_;
    bool operator<(const TradeInfo t){return profit_ < t.profit_;}
    bool operator>(const TradeInfo t) { return profit_ > t.profit_; }
    bool operator==(const TradeInfo t) { return profit_ == t.profit_; }
    bool operator!=(const TradeInfo t) { return profit_ != t.profit_; }
};

#include "util.hpp"
#include "DirectMethod.hpp"
#include "RecurMethod.hpp"
#include "IterMethod.hpp"
#endif  //_MAX_SUB_SET_H_