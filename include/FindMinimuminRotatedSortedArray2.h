#include <vector>
                                        // Numbers could be duplicate
int findMin(std::vector<int>& nums)     // [3,4,5,0,1,2,3,3] find 0
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
        else if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
        {
            r--;
        }
    }
    return nums[l];
}