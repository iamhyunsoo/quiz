#include <vector>

int findMin(std::vector<int>& nums)     // [3,4,5,0,1,2] find 0
{
    int l = 0;
    int r = nums.size() - 1;
    int mid {0};
    while (l < r)
    {
        mid = (l + r) / 2;
        if (nums[mid] < nums[r])
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return nums[l];
}