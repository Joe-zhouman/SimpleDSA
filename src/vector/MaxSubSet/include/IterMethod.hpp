#pragma once
#ifndef _ITER_METHOD_HPP_
#define _ITER_METHOD_HPP_

template <typename T>
TradeInfo<T> MaxSubSetIter(Vector<T> price) {
    TradeInfo<T> trade = {price[1] - price[0], 0, 1};
    for (auto i = 1; i < price.Size() - 1; i++) {
        if (trade.profit_ < (price[i + 1] - price[trade.buying_day_])) {
            trade.profit_ = price[i + 1] - price[trade.buying_day_];
            trade.saling_day_ = i + 1;
        }
        if (trade.profit_ < (price[i + 1] - price[i])) {
            trade.profit_ = price[i + 1] - price[i];
            trade.buying_day_ = i;
            trade.saling_day_ = i + 1;
        }
    }
    return trade;
}

#endif  //_ITER_METHOD_HPP_