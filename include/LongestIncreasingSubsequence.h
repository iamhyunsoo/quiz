#include <algorithm>
#include <vector>

int lengthOfLIS(std::vector<int>& nums)
{
	std::vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
		if (it == res.end())
		{
			res.push_back(nums[i]);
		}
		else
		{
			*it = nums[i];
		}
	}
	return static_cast<int>(res.size());
}

class Solution
{
public:
	int lengthOfLIS(std::vector<int> &nums)
	{
		std::vector<int> res;
        res.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = nums[i];
			if (tmp > res.back())
			{
				res.push_back(tmp);
			}
			else
			{
				int j = binarySearch(res, tmp);
				res[j] = tmp;
			}
		}
		return res.size();
	}
private:
	int binarySearch(std::vector<int>& res, const int& num)
	{
		int l {0};
		int r = res.size() - 1;
		int mid {0};
		while (l < r)
		{
			mid = (l + r) / 2;
			if (res[mid] == num)
			{
				return mid;
			}

			if (num > res[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		return l;
	}
};
