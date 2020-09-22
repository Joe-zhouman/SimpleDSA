#pragma once
#ifndef _DIRECT_METHOD_HPP_
#define _DIRECT_METHOD_HPP_

template <typename T>
TradeInfo<T> MaxSubSetDirectly(Vector<T> price) {
    TradeInfo<T> trade;
    PrintVector(price);
    trade.profit_ = price[0];
    trade.buying_day_ = 0;
    trade.saling_day_ = 1;
    for (auto i = 0; i < price.Size(); i++) {
        auto sum = price[i];
        if (trade.profit_ < sum) {
            trade.profit_ = sum;
            trade.buying_day_ = i;
            trade.saling_day_ = i + 1;
        }
        for (auto j = i + 1; j < price.Size(); j++) {
            sum += price[j];
            if (trade.profit_ < sum) {
                trade.profit_ = sum;
                trade.buying_day_ = i;
                trade.saling_day_ = j + 1;
            }
        }
    }
    return trade;
}
#endif  //_DIRECT_METHOD_HPP_
