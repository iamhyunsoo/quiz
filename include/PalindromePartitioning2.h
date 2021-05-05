#include <algorithm>
#include <string>

int minCut(std::string s)
{
    const int len = s.length();
    if (len <= 1)
    {
        return 0;
    }

    int dp[len+1];
    int i {0};
    int j {0};
    for (; i <= len; i++)       //EXAMPLE, s = "aab";
    {                           //dp = {-1, 0, 1, 2}
        dp[i] = i - 1;          //       0  1  2  3   <-- It means that 3-letter-word can have 2 partition at most
    }                           //                                      
    
    for (i = 1; i < len; i++)
    {
        for (j = 0; (i >= j) && (i + j < len) && (s[i - j] == s[i + j]); j++)
        {
            dp[i + j + 1] = std::min( dp[i + j + 1], dp[i - j] + 1); 
        }
        for (j = 0; (i >= j + 1) && (i + j < len) && (s[i - j - 1] == s[i + j]); j++)
        {
            dp[i + j + 1] = std::min( dp[i + j + 1], dp[i - j - 1] + 1);
        }
    }
    return dp[len];
}
