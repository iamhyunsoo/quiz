#include <vector>

using std::vector;

bool search(vector<int>& nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = 0;

    while (s <= e)
    {
        mid = (s + e) / 2;
        if (nums[mid] == target)
            return true;
        
        if (nums[s] == nums[mid] && nums[e] == nums[mid])
        {
            s++;
            e--;
            continue;
        }

        if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return false;
}