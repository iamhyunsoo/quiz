int maxSubArrayLen(vector<int>& nums, int k) {
    int accumulatedSum = 0;
    int ans = 0;
    std::unordered_map<int, int> dict;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        accumulatedSum += nums[i];
        if (accumulatedSum == k)
        {
            ans = i + 1;
        }
        if (dict.find( accumulatedSum - k ) != dict.end())
        {
            ans = std::max( ans, (int)(i - dict[ accumulatedSum - k ]) );
        }

        if (dict.find( accumulatedSum ) == dict.end())
        {
            dict[accumulatedSum] = i;
        }
    }
    return ans;
}
