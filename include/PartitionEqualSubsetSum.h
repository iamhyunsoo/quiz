#include <bitset>
bool canPartition(vector<int>& nums) 
{
	constexpr int MAX_NUM = 100;
	constexpr int MAX_SIZE = 200;
	std::bitset<MAX_NUM* MAX_SIZE / 2 + 1> bits(1);

	int sum = std::accumulate(nums.begin(), nums.end(), 0);
	for (int const& num : nums)
	{
		bits |= bits << num;
	}

	return !(sum & 1) && bits[sum >> 1];
}
