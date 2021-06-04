#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums)
{
    const int size = nums.size();
    if (!size)
        return 0;

    std::vector<int> sums(size + 1, 0);
    int ans = INT_MAX;

    for (int i = 1; i <= size; i++)
    {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    
    for (int i = i; i <= size; i++)
    {
        int tmp = target + sums[i -1];
        auto lower = std::lower_bound(sums.begin(), sums.end(), tmp);
        if (lower != sums.end())
        {
            ans = std::min( ans, static_cast<int>(lower - (sums.begin() + i - 1)) );
        }
    }
    
    return (ans != INT_MAX) ? ans : 0;
}