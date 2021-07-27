#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
	int maxEnvelopes(std::vector<std::vector<int>>& envelopes) 
	{
		std::sort(envelopes.begin(), envelopes.end(),
			[](std::vector<int> const& a, std::vector<int> const& b) {
				return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
			});

		std::vector<int> dp;
		for (auto const& en : envelopes)
		{
			auto it = std::lower_bound(dp.begin(), dp.end(), en[1]);
			if (it == dp.end())
			{
				dp.push_back(en[1]);
			}
			else if (*it > en[1])
			{
				*it = en[1];
			}
		}
		return dp.size();
	}
	
	int maxEnvelopesDP(std::vector<std::vector<int>>& envelopes)
	{
		const int size = envelopes.size();
		std::vector<int> dp(size, 1);
		std::sort(envelopes.begin(), envelopes.end());
		
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
				{
					dp[i] = std::max(dp[i], dp[j] + 1);
				}
			}
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};
