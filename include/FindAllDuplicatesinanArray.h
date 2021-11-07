#include <cmath>
#include <vector>

class Solution442
{
public:
	std::vector<int> findDuplicates(std::vector<int>& nums)
	{
		std::vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[std::abs(nums[i]) - 1] < 0)
			{
				ret.push_back(std::abs(nums[i]));
			}
			nums[std::abs(nums[i]) - 1] = -nums[std::abs(nums[i]) - 1];
		}
		return ret;
	}
};
