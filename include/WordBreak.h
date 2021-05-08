#include <algorithm>
#include <string>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    const int len = s.length();
    std::vector<bool> dp(len + 1, false);
    dp[0] = true;

    for (int i = 1; i <= len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                if (std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[len];
}