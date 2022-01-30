class Solution 
{
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        const int len = (int)nums.size();
        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i; j < len; j++)
            {
                dp[i][j] = (i == j) ? nums[i] : std::max(nums[i] - dp[i+1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1] >= 0;
    }
};
