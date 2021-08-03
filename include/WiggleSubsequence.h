#include <algorithm>
#include <vector>

class Solution 
{
public:
    int wiggleMaxLength(std::vector<int>& nums) 
	{
		int up   {1};
		int down {1};
		int sign {0};
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i - 1] && sign != 2)
			{
				up = down + 1;
				sign = 2;
			}
			else if (nums[i] < nums[i - 1] && sign != 1)
			{
				down = up + 1;
				sign = 1;
			}
		}
		return std::max(up, down);
    }
};