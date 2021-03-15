#include <vector>

int RemoveElement(std::vector<int>& nums, int val)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            count++;
        }
        else
        {
            nums[i - count] = nums[i];
        }
    }
    return nums.size() - count;
}