#ifdef AVG
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int len = s.length();
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, 0));
        int cnt {0};
        
        for (int i = 0; i < len; i++) 
        { 
            dp[i][i] = 1; 
            cnt++; 
        }
        for (int i = 0; i < len - 1; i++)
        {
            dp[i][i+1] = (s[i] == s[i + 1]);
            cnt += dp[i][i + 1];
        }
        for (int length = 3; length <= len; length++)
        {
            for (int i = 0, j = i + length - 1; j < len; i++, j++)
            {
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                cnt += dp[i][j];
            }
        }
        
        return cnt;
    }
};
#endif


#ifdef WORST
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int len = s.length();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        for (int i = 1; i <= len; i++)
        {
            for (int j = i; j <= len; j++)
            {
                if (i == j)
                {
                    dp[i][j] = dp[i - 1][len] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    
                    bool isPalin = true;
                    int cpI = i-1;
                    int cpJ = j-1;
                    while (cpI < cpJ)
                    {
                        if (s[cpI] != s[cpJ])
                        {
                            isPalin = false;
                            break;
                        }
                        cpI++;
                        cpJ--;
                    }
                    
                    dp[i][j] += (isPalin);
                }
            }
        }
        return dp[len][len];
    }
};
#endif
