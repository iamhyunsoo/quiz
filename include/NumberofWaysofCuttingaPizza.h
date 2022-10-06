class Solution {
    std::vector<std::vector<std::vector<int>>> dp;
    std::vector<std::vector<int>> preSum;
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        dp.assign(k, std::vector(m, std::vector<int>(n, -1)));
        preSum.assign(m + 1, std::vector<int>(n + 1, 0)); 
        
        // Prefix sum
        for (int i = m - 1;  i >= 0; --i)
        {
            for (int j = n - 1;  j >= 0; --j)
            {
                preSum[i][j] = (pizza[i][j] == 'A') + preSum[i+1][j] + preSum[i][j+1] - preSum[i+1][j+1];
            }
        }
        return helper(0, 0, k - 1, m, n);
    }
private:
    int helper(int r, int c, int k, int m, int n)
    {
        if (preSum[r][c] == 0) { return 0; }
        if (k == 0) { return 1; }
        if (dp[k][r][c] != -1) { return dp[k][r][c]; }

        int ways {0};
        for (int i = r + 1; i < m; ++i)
        {
            if (preSum[r][c] - preSum[i][c] > 0)
            {
                ways = (ways + helper(i, c, k - 1, m, n)) % 1000000007;
            }
        }
        for (int j = c + 1; j < n; ++j)
        {
            if (preSum[r][c] - preSum[r][j] > 0)
            {
                ways = (ways + helper(r, j, k - 1, m, n)) % 1000000007;
            }
        }
        return dp[k][r][c] = ways;
    }
};
