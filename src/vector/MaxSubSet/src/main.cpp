#include <iostream>

#include "MaxSubSet.h"
using namespace std;
int main(int argc, char const *argv[]) {
    int arr1[] = {13, -3, -25, 20, -3,  -16, -23, 18,
                  20, -7, 12,  -5, -22, 15,  -4,  7};
    Vector<int> price_change(arr1, 16);
    int arr2[] = {100, 113, 110, 85,  105, 102, 86, 63, 81,
                  101, 94,  106, 101, 79,  94,  90, 97};
    Vector<int> price(arr2, 16);
    auto trade = MaxSubSetIter(price);
    cout << "buy in day " << trade.buying_day_ + 1 << endl;
    cout << "sale in day " << trade.saling_day_ + 1 << endl;
    cout << "profit of this trade will be " << trade.profit_ << endl;
    return 0;
}
