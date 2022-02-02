class Solution 
{
public:
    int checkRecord(int n) 
    {
        int MOD=1000000007;
        std::vector<long> dp(n <= 4 ? 5 : n+1, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;
        
        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] * 2) % MOD + (MOD - dp[i - 4])) % MOD;
        }
        long cnt = dp[n];
        for (int i = 1; i <= n; i++)
        {
            cnt += (dp[i - 1] * dp[n - i]) % MOD;
        }
        return static_cast<int>(cnt % MOD); 
    }
};
