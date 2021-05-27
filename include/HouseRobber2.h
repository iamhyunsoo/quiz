#include <algorithm>
#include <vector>

class Solution
{
public:
    int rob(std::vector<int>& nums)
    {
        const int size = nums.size();
        if (size <= 1)
        {
            return size ? nums[0] : 0;
        }
        return std::max(rob(nums, 0, size - 1), rob(nums, 1, size));
    }
private:
    int rob(std::vector<int> const& nums, int l, int r)
    {
        int prev{0};
        int curr{0};
        for (int i = l; i < r; i++)
        {
            int tmp = std::max(prev + nums[i], curr);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};