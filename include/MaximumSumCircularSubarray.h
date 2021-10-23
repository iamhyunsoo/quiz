#include <algorithm>
#include <vector>

int maxSubarraySumCircular(vector<int>& nums) 
{
  int maxSum = nums[0];
  int minSum = nums[0];
  int currMax = 0;
  int currMin = 0;
  int sum = 0;
  
  for (int const& num : nums)
  {
    sum += num;
    currMax = std::max(currMax + num, num);
    maxSum  = std::max(maxSum, currMax);
    currMin = std::min(currMin + num, num);
    minSum  = std::min(minSum, currMin);
  }
  return maxSum > 0 ? std::max(maxSum, sum - minSum) : maxSum;
}
