class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)   // Bottom Up
    {
        int n = nums.size();
        int m = multipliers.size();
        std::vector<std::vector<int>> dp(m+1, (std::vector<int>(m+1, 0)));
        
        for (int i = m - 1; i >= 0; i--)
        {
            for (int left = i; left >= 0; left--)
            {
                int right = (n - 1) - (i - left);
                dp[i][left] = std::max(
                    nums[left] * multipliers[i] + dp[i+1][left + 1],
                    nums[right] * multipliers[i] + dp[i+1][left]
                );
            }
        }
        return dp[0][0];
    }
};

/*
class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)   //Top-Down
    {
        this->n = nums.size();
        this->m = multipliers.size();
        dp.assign(m+1, std::vector<int>(m+1,0));
        this->nums = nums;
        this->multipliers = multipliers;
        return helper(0, 0);
    }
    
    int helper(int i, int left)
    {
        if (i == m) return 0;
        
        if (dp[i][left] == 0)
        {
            int right = (n - 1) - (i - left);
            dp[i][left] = std::max(
                nums[left] * multipliers[i] + helper(i+1, left+1),
                nums[right] * multipliers[i] + helper(i+1, left)
            );
        }
        return dp[i][left];
    }
    
private:
    vector<int> nums;
    vector<int> multipliers;
    int n;
    int m;
    vector<vector<int>> dp;
};
*/
