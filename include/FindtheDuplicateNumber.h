#include <vector>

int findDuplicate(std::vector<int>& nums)
{
	auto slow = nums[0];
	auto fast = nums[0];
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
	} while (slow != fast);

	slow = nums[0];
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}
	return fast;
}