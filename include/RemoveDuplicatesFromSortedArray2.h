#include <vector>

//Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
int RemoveDuplicates(std::vector<int>& nums)
{
    int i {0};
    for (auto& x : nums)
    {
        if (i < 2 || x > nums[i - 2])
        {
            nums[i++] = x;
        }
    }
    return i;
}