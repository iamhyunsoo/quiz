class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        const int len1 = word1.length();
        const int len2 = word2.length();
        std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1, 0));
        
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if (!i || !j)
                {
                    dp[i][j] = i + j;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};
