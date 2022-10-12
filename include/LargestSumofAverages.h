class Solution {
    std::vector<std::vector<double>> dp;
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n + 1, std::vector<double>(k + 1, 0));
        double sumAvg {0};
        for (int i = 0; i < n; ++i)
        {
            sumAvg += nums[i];
            dp[i + 1][1] = sumAvg / (i + 1); 
        }
        return partitionSum(n, k, nums);
    }
private:
    double partitionSum(int n, int k, vector<int>& nums)
    {
        if (dp[n][k]) { return dp[n][k]; }
        if (n < k) { return 0; }
        double sum {0};
        for (int i = n - 1; i > 0; --i)
        {
            sum += nums[i];
            dp[n][k] = std::max(dp[n][k], (sum / (n - i)) + partitionSum(i, k - 1, nums));
        }
        return dp[n][k];
    }
};
