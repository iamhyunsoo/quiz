class Solution 
{
    public:
    int minTaps(int n, vector<int>& ranges) 
    {
        std::vector<int> dp(n+1, 10001);
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++)
        {
            int left = std::max(0, i - ranges[i]);
            int right = std::min(n, i + ranges[i]);
            for (int j = left + 1; j <= right; j++)
            {
                dp[j] = std::min(dp[left] + 1, dp[j]);
            }
        }
        
        return dp[n] >= 10001 ? -1 : dp[n];
    }
};
