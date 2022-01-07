class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        std::vector<std::vector<int>> dp(text1.length()+1, std::vector<int>(text2.length()+1, 0));
        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};

/*
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) // Top Down.. Slower..
    {
        mDP.assign(text1.length()+1, std::vector<int>(text2.length()+1, -1));
        mText1 = text1;
        mText2 = text2;
        return helper(0, 0);
    }
    
    int helper(int i, int j)
    {
        if (i == mText1.length() || j == mText2.length()) return 0;
        if (mDP[i][j] != -1)
        {
            return mDP[i][j];
        }
        
        int maxLen {0};
        if (mText1[i] == mText2[j])
        {
            maxLen = 1 + helper(i + 1, j + 1);
        }
        else
        {
            maxLen = std::max(helper(i, j+1), helper(i + 1, j));
        }
        mDP[i][j] = maxLen;
        return mDP[i][j];
    }
    
private:
    std::vector<std::vector<int>> mDP;
    std::string mText1;
    std::string mText2;
};
*/
