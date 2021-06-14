#include <deque>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	const int size = nums.size();
	std::vector<int> res(size - k + 1);
	std::deque<int> dq;
	for (int i = 0; i < size; i++)
	{
		while (dq.size() && i - dq.front() >= k)
		{
			dq.pop_front();
		}
		while (dq.size() && nums[dq.front()] < nums[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
		if (i >= k - 1)
		{
			res[i - (k - 1)] = (nums[dq.front()]);
		}
	}
	return res;
}