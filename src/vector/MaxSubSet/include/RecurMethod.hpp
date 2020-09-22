#pragma once
#ifndef _RECUR_METHOD_HPP_
#define _RECUR_METHOD_HPP_

template <typename T>
TradeInfo<T> MaxCrossSubSet(Vector<T> price, int lo, int mi, int hi) {
    T left_sum = lb;
    T sum = 0;
    TradeInfo<T> trade;
    for (int i = mi - 1; lo <= i; i--) {
        sum += price[i];
        if (left_sum < sum) {
            left_sum = sum;
            trade.buying_day_ = i;
        }
    }
    T right_sum = lb;
    sum = 0;
    for (size_t i = mi; i < hi; i++) {
        sum += price[i];
        if (right_sum < sum) {
            right_sum = sum;
            trade.saling_day_ = i + 1;
        }
    }
    trade.profit_ = left_sum + right_sum;
    return trade;
}
template <typename T>
TradeInfo<T> MaxSubSetRecur(Vector<T> price, int lo, int hi) {
    if (hi - lo < 2){
        TradeInfo<T> trade = {price[lo], lo, hi};
        return trade;
    }
        
    else {
        int mi = (lo + hi) >> 1;
        auto l_trade = MaxSubSetRecur(price, lo, mi);
        auto r_trade = MaxSubSetRecur(price, mi, hi);
        auto m_trade = MaxCrossSubSet(price, lo, mi, hi);
        if (l_trade.profit_ >= r_trade.profit_ &&
            l_trade.profit_ >= m_trade.profit_)
            return l_trade;
        else if (r_trade.profit_ >= l_trade.profit_ &&
                 r_trade.profit_ >= m_trade.profit_)
            return r_trade;
        else
            return m_trade;
    }
}
template <typename T>
TradeInfo<T> MaxSubSetRecur(Vector<T> price) {
    return MaxSubSetRecur(price, 0, price.Size());
}
#endif  //_RECUR_METHOD_HPP_
