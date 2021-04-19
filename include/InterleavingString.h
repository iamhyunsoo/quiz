#include <string>
#include <vector>
using std::string;
using std::vector;
#include <iostream>
using namespace std;

bool isInterleave2D(string s1, string s2, string s3)          //use 2D vector here
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    if (l3 != (l1 + l2))
    {
        return false;
    }

    vector< vector<bool> > dp(l1 + 1, vector<bool>(l2 + 1, false));
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;

            }
            else if (i == 0)
            {              
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];

            }
            else if (j == 0)
            {             
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];

            }
            else
            {               
                dp[i][j] = ( dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1] ) ) || ( dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]) );
            }
        }
    }
    return dp[l1][l2];
}

bool isInterleave1D(string s1, string s2, string s3)          //[BETTER] use 1D vector here
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    if (l3 != (l1 + l2))
    {
        return false;
    }

    vector<bool> dp(l2 + 1, false);
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[j] = true;
            }
            else if (i == 0)
            {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
            else if (j == 0)
            {
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            }
            else
            {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1] || dp[j] && s1[i - 1] == s3[i + j - 1];
            }
        }
    }
    return dp[l2];
}
