#include <algorithm>
#include <vector>

int maximumSubarray(std::vector<int>& nums)
{
    int curr = nums[0];
    int ans = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        curr = std::max(curr + nums[i], nums[i]);   //if nums[i] is greater than cumulative sum, renew the start
        ans = std::max(curr, ans);
    }
    return ans;
}