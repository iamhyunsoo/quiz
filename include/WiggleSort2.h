#include <algorithm>
#include <vector>

void wiggleSort(std::vector<int>& nums)
{
	std::vector<int> sorted(nums);
	std::sort(sorted.begin(), sorted.end());
	for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
	{
		nums[i] = sorted[i & 1 ? k++ : j++];
	}
}
