#include <algorithm>
#include <vector>

int maxProduct(std::vector<int>& nums) 
{
    int currMax = nums[0];
    int currMin = nums[0];
    int ans = nums[0];

    int tmp1 {0};
    int tmp2 {0};
    for (int i = 1; i < nums.size(); i++)
    {
        tmp1 = currMax * nums[i];
        tmp2 = currMin * nums[i];

        currMax = std::max(nums[i], std::max(tmp1, tmp2));
        currMin = std::min(nums[i], std::min(tmp1, tmp2));
        ans = std::max(ans, currMax);
    }
    return ans;
}