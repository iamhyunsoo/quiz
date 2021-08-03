#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

class Solution
{
public:
    int combinationSum4(std::vector<int>& nums, int target)
    {
		std::sort(nums.begin(), nums.end());
		std::vector<long> dp(target + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= target; i++)
		{
			int cnt {0};
			for (auto const& n : nums)
			{
				int rem = i - n;
				if (rem < 0) 
				{
					break;
				}
				cnt += dp[rem];
			}
			dp[i] = cnt;	
		}
		return dp[target];
    }
};