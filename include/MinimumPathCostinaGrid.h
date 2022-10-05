// Bottom-Up 
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
        dp[0] = grid[0];
        for (int lv = 1; lv < m; ++lv)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    dp[lv][k] = std::min(dp[lv][k], grid[lv][k] + dp[lv - 1][j] + moveCost[grid[lv - 1][j]][k]); 
                }
            }
        }
        return *std::min_element(dp.back().begin(), dp.back().end());
    }
};

// Top-Down
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        std::function<int(int, int)> helper = [&](int level, int side) {
            if (level == m - 1)
            {
                return grid[level][side];
            }
            if (dp[level][side] >= 0)
            {
                return dp[level][side];
            }

            std::vector<int> tmp(n, 0);
            for (int i = 0; i  < n; ++i)
            {
                tmp[i] = helper(level + 1, i);
            }

            auto costs = moveCost[grid[level][side]];
            int res = INT_MAX;
            for (int i = 0; i < costs.size(); ++i)
            {
                res = std::min(res, costs[i] + tmp[i]);
            }
            res += grid[level][side];
            dp[level][side] = res;
            return res;
        };

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            ans = std::min(ans, helper(0, i));
        }
        return ans;
    }
};
