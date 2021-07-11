#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int coinChange(std::vector<int>& coins, int n) 
{
	std::sort(coins.begin(), coins.end());
	std::vector<int> dp(++n, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		for (auto const& coin : coins)
		{
			if (i - coin < 0)
			{
				break;
			}
			else if (dp[i - coin] != INT_MAX)
			{
				dp[i] = std::min(dp[i], dp[i - coin] + 1);
			}
		}
	}
	return dp[--n] == INT_MAX ? -1 : dp[n];
}