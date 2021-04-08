#include <algorithm>    
#include <vector>

void sortColors(std::vector<int>& nums)
{
    for (int i = 0, l = 0, r = nums.size() - 1; i <= r; i++)
    {
        if (nums[i] == 0)
        {
            std::swap(nums[l++], nums[i]);
        }
        else if (nums[i] == 2)
        {
            std::swap(nums[i--], nums[r--]);
        }
    }
}
