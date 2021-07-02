#include <algorithm>
#include <vector>

using namespace std;

int maxCoins(std::vector<int>& nums) 
{
	const int size = nums.size();
	if (!size) return 0;

	std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
	for (int len = 1; len <= size; ++len)
	{
		for (int i = 0; i <= size - len; ++i)
		{
			int j = i + len - 1;
			for (int k = i; k <= j; ++k)
			{
				int lValue = 1;
				int rValue = 1;
				if (i != 0)
				{
					lValue = nums[i - 1];
				}
				if (j != size - 1)
				{
					rValue = nums[j + 1];
				}

				int before = 0;
				int after  = 0;
				if (i != k)
				{
					before = dp[i][k - 1];
				}
				if (j != k)
				{
					after = dp[k + 1][j];
				}
				dp[i][j] = std::max(dp[i][j], before + after + (lValue * nums[k] * rValue));
			}
		}
	}	
	return dp[0][size - 1];
}