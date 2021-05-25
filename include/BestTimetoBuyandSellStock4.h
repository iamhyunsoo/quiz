#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int maxProfit(int k, std::vector<int>& prices)
{
    const int size = prices.size();
    if (size <= 1)
    {
        return 0;
    }

    std::vector<int> buys(size + 1, INT_MIN);
    std::vector<int> sells(size + 1, 0);

    for (auto const& price : prices)
    {
        for (int i = 1; i <= k; i++)
        {
            buys[i] = std::max(buys[i], sells[i - 1] - price);
            sells[i]= std::max(sells[i], buys[i] + price);
        }
    }
    return sells[k];
}

/*
prices = [3,2,6,5,0,3] , k = 2
buy = [min, min, min]  sell = [0, 0, 0]

--prices[0]--
buy = [min, -3, min]
sell= [0, 0, 0]

buy = [min, -3, -3]
sell= [0, 0, 0]
--

--prices[1]--
buy = [min, -2, -2]
sell= [0, 0, 0]

buy = [min, -2, -2]
sell= [0, 0, 0]
--

--prices[2]--
buy = [min, -2, -2]
sell= [0, 4, 0]

buy = [min, -2, -2]
sell= [0, 4, 4]
--

--prices[3]--
buy = [min, -2, -2]
sell= [0, 4, 4]

buy = [min, -2, -1]
sell= [0, 4, 4]
--

--prices[4]--
buy = [min, 0, -1]
sell= [0, 4, 4]

buy = [min, 0, 4]
sell= [0, 4, 4]
--

--prices[5]--
buy = [min, 0, 4]
sell= [0, 4, 4]

buy = [min, 0, 4]
sell= [0, 4, 7]
--


*/