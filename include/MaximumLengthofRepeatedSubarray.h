class Solution
{
public:
    int findLength(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (!m || !n) return 0;
        int ret {0};
        std::vector<int> dp(n + 1, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                dp[j] = nums1[i] == nums2[j] ? 1 + dp[j + 1] : 0; 
                ret = std::max(ret, dp[j]);
            }
        }
        return ret;
    }
};
