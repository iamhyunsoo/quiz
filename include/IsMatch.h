#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool isMatch(string s, string p)
    {
        int sLen = s.length();
        int pLen = p.length();

        vector<vector<bool> > T (sLen + 1, vector<bool> (pLen + 1, 0));

        T[0][0] = true;
        int i {0};
        int j {0};
        for (i = 1; i <= pLen; i++)
        {
            if (p[i - 1] == '*')
            {
                T[0][i] = T[0][i - 2];
            }
        }
        for (i = 1; i <= sLen; i++)
        {
            for (j = 1; j <= pLen; j++)
            {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
                {
                    T[i][j] = T[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    T[i][j] = T[i][j - 2];
                    if (p[j - 2] == '.' || s[i - 1] == p[j - 2])
                    {
                        T[i][j] = T[i][j] | T[i - 1][j];
                    }
                }
                else
                {
                    T[i][j] = false;
                }
            }
        }
        return T[sLen][pLen];
    }
};