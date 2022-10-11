class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        for (int i = piles.size() - 2; i >= 0; --i) { piles[i] += piles[i + 1]; }
        std::vector<std::vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        return dfs(0, 1, piles, dp);
    }
private:
    int dfs(int idx, int M, std::vector<int>& piles, std::vector<std::vector<int>>& dp)
    {
        if (idx + 2 * M >= piles.size()) { return piles[idx]; }
        if (dp[idx][M]) { return dp[idx][M]; }
        int stones {0};
        for (int i = 1; i <= M * 2; ++i)
        {
            auto taken = piles[idx] - piles[idx + i];
            stones = std::max(stones, taken + piles[idx + i] - dfs(idx + i, std::max(i, M), piles, dp));
        }        
        return dp[idx][M] = stones;
    }
};
