#include <vector>
#include <bits/stdc++.h>

int maxProfit(std::vector<int>& prices) 
{
    int min = INT_MAX;
    int max {0};

    for (auto& x : prices)
    {
        if (x < min)
        {
            min = x;
        }
        else if (x - min > max)
        {
            max = x - min;
        }
    }
    return max;
}