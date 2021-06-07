#include <algorithm>
#include <queue>
#include <vector>

int findKthLargest(std::vector<int>& nums, int k)       // std::nth_element . . . SO useful
{
    std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
    return nums[k - 1];
}
int findKthLargest2(std::vector<int>& nums, int k)       // std::priority_queue 
{
    std::priority_queue<int> queue(nums.begin(), nums.end());
    for (int i = 0 ; i < k - 1 ; i++)
    {
        queue.pop();
    }
    return queue.top();
}