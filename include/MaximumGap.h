#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

int maximumGap(std::vector<int>& nums)   // Time Complexity Must be O(n) ! Not n^2.
{
    int size = nums.size();
    if (size < 2)
    {
        return 0;
    }

    int maxNum = *std::max_element(nums.begin(), nums.end());
    int minNum = *std::min_element(nums.begin(), nums.end());

    int interval = std::max( (maxNum - minNum) / (size - 1), 1 );
    int numOfBucket = (maxNum - minNum) / interval + 1;
    std::vector<int> bucketsMin(numOfBucket, INT_MAX);
    std::vector<int> bucketsMax(numOfBucket, INT_MIN);

    for (auto& num : nums)
    {
        int bucketIdx = (num - minNum) / interval;
        bucketsMin[bucketIdx] = std::min(bucketsMin[bucketIdx], num);   
        bucketsMax[bucketIdx] = std::max(bucketsMax[bucketIdx], num);   
    }

    int i {0};
    int j {0};
    int ans = bucketsMax[0] - bucketsMin[0];

    while (i < numOfBucket)
    {
        j = i + 1;
        while (j < numOfBucket && bucketsMin[j] == INT_MAX)
        {
            j++;
        }
        if (j == numOfBucket)
            break;
            
        ans = std::max( ans, bucketsMin[j] - bucketsMax[i] );
        
        i = j;
    }

    return ans;
}