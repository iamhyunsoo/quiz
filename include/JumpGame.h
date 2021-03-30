#include <vector>

bool canJump(std::vector<int>& nums)
{
    int pos = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (i + nums[i] >= pos)
        {
            pos = i;
        }
    }
    return pos == 0;
}