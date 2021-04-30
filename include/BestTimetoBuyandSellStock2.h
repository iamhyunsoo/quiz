#include <vector>
#include <bits/stdc++.h>

int maxProfit(std::vector<int>& prices) 
{
    int bottom {0};
    int sum {0};

    int i {0};
    int size = prices.size();

    while (i < size - 1)
    {
        while (i < size - 1 && prices[i] >= prices[i+1])
        {
            i++;
        }
        bottom = prices[i];
        while (i < size - 1 && prices[i] <= prices[i+1])
        {
            i++;
        }
        sum += prices[i] - bottom;
    }

    return sum;
}