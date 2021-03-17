#include <vector>
#include <algorithm>

class Solution 
{
public:
    void nextPermutation(std::vector<int>& nums) 
    {
        int i = nums.size() - 2;
        int j = i + 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i < 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        while (nums[i] >= nums[--j]);

        std::swap(nums[i], nums[j]);
        std::sort(nums.begin() + i + 1, nums.end());
    }
};