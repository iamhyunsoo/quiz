#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int change(int amount, std::vector<int>& coins) 
{
	std::sort(coins.begin(), coins.end());
	std::vector<int> dp(amount + 1);
	dp[0] = 1;
	for (auto const& coin : coins)
	{
		for (int i = coin; i <= amount; i++)
		{
			dp[i] += dp[i - coin];
		}
	}
	return dp[amount];
}