#include <string>
#include <vector>

// s = "babgbag", t = "bag"  => answer = 5
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
int numDistinct(std::string s, std::string t)
{
    int n = s.length();
    int m = t.length();

    std::vector< std::vector<int> > dp( m+1, std::vector<int>(n+1, 0) );        //In Leetcode, int should be unsigned long to pass the submission criteria
    int i {0};
    int j {0};

    for (; i <= n; i++)
    {
        dp[0][i] = 1;
    }    

    for (j = 1; j <= n; j++)
    {
        for (i= 1; i <= m; i++)
        {
            dp[i][j] = dp[ i ][ j - 1 ] + (s[j - 1] == t[i - 1] ? dp[i - 1][j - 1] : 0);
        }
    }
    return dp[m][n];
}

int numDistinct2(std::string s, std::string t) // 1-d array
{
    int n = s.length();
    int m = t.length();

    std::vector<int> dp( m+1, 0 );        //In Leetcode, int should be unsigned long to pass the submission criteria
    dp[0] = 1;

    int i {0};
    int j {0};

    for (j = 1; j <= n; j++)
    {
        int prev = 1;
        for (i= 1; i <= m; i++)
        {
            int tmp = dp[i];
            dp[i] = dp[ i ] + (s[j - 1] == t[i - 1] ? prev : 0);
            prev = tmp;
        }
    }
    return dp[m];
}