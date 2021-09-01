#include <algorithm>
#include <vector>

int maxRotateFunction(std::vector<int>& nums) 
{
    int currMax {0};
    int retMax {0};
    int size = nums.size();
    int totalSum {0};

    for (int i = 0 ; i < size; i++)
    {
        totalSum += nums[i];
        currMax += i * nums[i];
    }
    retMax = currMax;

    for (int i = size - 1; i >= 0; i--)
    {
        currMax = currMax + totalSum - (size * nums[i]);
        retMax = std::max(retMax, currMax); 
    } 

    return retMax;
}