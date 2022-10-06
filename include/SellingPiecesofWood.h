class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        std::vector<std::vector<long>> dp(m+1, std::vector<long>(n+1, 0));
        for (auto const& price : prices)
        {
            dp[price[0]][price[1]] = price[2];
        } 
        for (int r = 1; r <= m; ++r)
        {
            for (int c = 1; c <= n; ++c)
            {
                for (int k = 1; k <= r/2; ++k)
                {
                    dp[r][c] = std::max(dp[r][c], dp[k][c] + dp[r-k][c]);
                }

                for (int k = 1; k <= c/2; ++k)
                {
                    dp[r][c] = std::max(dp[r][c], dp[r][k] + dp[r][c-k]);
                }
            }
        }
        return dp[m][n];
    }
};
