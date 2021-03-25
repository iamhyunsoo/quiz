#include <algorithm>
#include <vector>

static int searchInsert(vector<int>& nums, int target)          //STL version
{
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}

static int searchInsertBinary(vector<int>& nums, int target)   //Binary version
{
    int l = 0;
    int r = nums.size() - 1;
    int mid {0};
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else 
        {
            return mid;
        }
    }
    return l;
}
