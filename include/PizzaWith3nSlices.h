class Solution {
public:
    int maxSizeSlices(std::vector<int>& slices) {
        int k = slices.size() / 3;
        std::vector<int> first = slices;
        first.erase(first.begin());
        slices.pop_back();
        return std::max(helper(first, k), helper(slices, k));
    }
private:
    int helper(std::vector<int>& slices, int k)
    {
        int n = slices.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                if (i == 1)
                {
                    dp[i][j] = slices[i-1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i-1][j], dp[i-2][j-1] + slices[i-1]);
                }
            }
        }
        return dp[n][k];
    }
};
