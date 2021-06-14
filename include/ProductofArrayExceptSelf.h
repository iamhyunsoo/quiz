#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
	const int size = nums.size();
	std::vector<int> prodExceptSelf(size,1);
	for (int i = 1; i < size; i++)
	{
		prodExceptSelf[i] = prodExceptSelf[i - 1] * nums[i - 1];
	}
	int r = 1;
	for (int i = size - 1; i > 0; i--)
	{
		r *= nums[i];
		prodExceptSelf[i - 1] *= r;
	}
	return prodExceptSelf;
}