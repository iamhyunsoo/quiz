#include <algorithm>
#include <vector>

int smallestDistancePair(std::vector<int>& nums, int k) 
{
    std::sort(nums.begin(), nums.end());
    int low {0};
    int high = nums.back() - nums[0];
    while( low < high )
    {
        int mid = (high + low) / 2;
        int cnt {0};
        int l {0};
        for (int r = 0; r < nums.size(); r++)
        {
            while (nums[r] - nums[l] > mid)
            {
                l++;
            }
            cnt += (r - l);
        }
        if (cnt >= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
