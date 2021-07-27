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
};
