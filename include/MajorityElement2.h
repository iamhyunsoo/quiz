#include <algorithm>
#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums)
{
	int candidate1 {0};
	int candidate2 {0};
	int cnt1 {0};
	int cnt2 {0};

	for (auto const& num : nums)
	{
		if (candidate1 == num)
		{
			cnt1++;
		}
		else if (candidate2 == num)
		{
			cnt2++;
		}
		else if (!cnt1)
		{
			candidate1 = num;
			cnt1++;
		}
		else if (!cnt2)
		{
			candidate2 = num;
			cnt2++;
		}
		else
		{
			cnt1--;
			cnt2--;
		}
	}

	cnt1 = 0;
	cnt2 = 0;
	for (auto const& num : nums)
	{
		if (num == candidate1)
		{
			cnt1++;
		}
		else if (num == candidate2)
		{
			cnt2++;
		}
	}

	if (cnt1 < cnt2)
	{
		std::swap(candidate1, candidate2);
		std::swap(cnt1, cnt2);
	}
	int limit = nums.size() / 3;
	return cnt1 <= limit ? std::vector<int>{} : cnt2 <= limit ? std::vector<int>{candidate1} : std::vector<int>{candidate1, candidate2}; 
}