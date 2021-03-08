#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

int ThreeSum(std::vector<int> vec, int target)
{
    int diff = INT_MAX;
    int sz = vec.size();
    sort(begin(vec), end(vec));
    
    for (int i = 0; i < sz && diff != 0; ++i) 
    {
        int lo = i + 1;
        int hi = sz - 1;
        while (lo < hi) 
        {
            int sum = vec[i] + vec[lo] + vec[hi];
            
            if (abs(target - sum) < abs(diff))
                diff = target - sum;
            
            if (sum < target)
                ++lo;
            else
                --hi;
        }
    }
    return target - diff;
}
