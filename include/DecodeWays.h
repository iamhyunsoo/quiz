#include <string>


int numDecodings(std::string s)
{
    if (s[0] == '0')
        return 0;
    
    if (s.length() == 1)
        return 1;

    int size = s.length();
    int dp[size];

    dp[0] = 1;
    dp[1] = (s[0] == '1' || (s[0] == '2' && s[1] < '7') ? 1 : 0) + (s[1] != '0');

    for (int i = 2; i < size; i++)
    {
        if (s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2'))
        {
            return 0;
        }

        dp[i] = (s[i] != '0') ? dp[i-1] : 0;

        if (s[i - 1] == '1' || (s[i -1] == '2' && s[i] < '7'))
        {
            dp[i] += dp[i - 2];
        }        
    }

    return dp[size-1];
}