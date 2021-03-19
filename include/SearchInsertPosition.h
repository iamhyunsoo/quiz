#include <algorithm>
#include <vector>

static int searchInsert(vector<int>& nums, int target) 
{
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}
