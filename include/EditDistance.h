#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int editDistance(const std::string &word1, const std::string &word2) //Best one
{
    int w1 = word1.length();
    int w2 = word2.length();
    std::vector<int> dp(w2 + 1, 0);

    int i{1};
    int j{1};

    for (; j <= w2; j++)
    {
        dp[j] = j;
    }

    int prev{0};
    int temp{0};
    for (; i <= w1; i++)
    {
        prev = dp[0];
        dp[0] = i;
        for (j = 1; j <= w2; j++)
        {
            temp = dp[j];

            if (word1[i - 1] == word2[j - 1])
            {
                dp[j] = prev;
            }
            else
            {
                dp[j] = std::min(prev, std::min(dp[j - 1], dp[j])) + 1;
            }
            prev = temp;
        }
    }
    return dp[w2];
}

int minDistance(string word1, string word2)         //NOrmal one
{
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int i{1};
    int j{1};
    for (; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[m][n];
}