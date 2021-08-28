std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
{
    int size = nums.size();
    std::vector<int> dp(size, 0);
    std::vector<int> parent(size, 0);
    std::vector<int> ret;

    std::sort(std::begin(nums), std::end(nums));

    int numOfSubset = 0;
    int firstIdxOfSubset = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = i; j < size; j++)
        {
            if (nums[j] % nums[i] == 0 && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;

                if (dp[i] > numOfSubset)
                {
                    numOfSubset = dp[i];
                    firstIdxOfSubset = i;
                }
            }
        }
    }
    
    for (int i = 0; i < numOfSubset; i++)
    {
        ret.push_back(nums[firstIdxOfSubset]);
        firstIdxOfSubset = parent[firstIdxOfSubset];
    }

    return ret;
}
