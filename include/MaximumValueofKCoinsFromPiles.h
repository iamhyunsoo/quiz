class Solution {
    std::vector<std::vector<int>> dp;
    int n;
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.assign(n + 1, std::vector<int>(k + 1, 0));
        return helper(piles, 0, k);
    }
private:
    int helper(vector<vector<int>>& piles, int ith, int k)
    {
        if (ith == n || k == 0) { return 0; }
        if (dp[ith][k] > 0) { return dp[ith][k]; }
        int res = helper(piles, ith + 1, k);
        int curSum = 0;
        for (int i = 0; i < piles[ith].size() && i < k; ++i)
        {
            curSum += piles[ith][i];
            res = std::max(res, curSum + helper(piles, ith+1, k - i - 1));
        }
        dp[ith][k] = res;
        return res;
    }
};
