#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

int maxProfit(std::vector<int>& prices) 
{
    int p1 {0};     //first profit
    int p2 {0};     //second profit
    int firstBuy {INT_MAX};
    int secondBuy {INT_MAX};

    for (auto& price : prices)
    {
        firstBuy = std::min(firstBuy, price);
        p1 = std::max(p1, price - firstBuy);
        secondBuy = std::min(secondBuy, price - p1);
        p2 = std::max(p2, price - secondBuy);
    }
    return p2;
}