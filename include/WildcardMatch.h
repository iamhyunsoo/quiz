#include <string>


class Solution                                          //" abcda "
{                                                       //" a*a "      => true
public:                                                 //" ?*a "      => true
    static int dfs(const std::string& s, const std::string& p, int si, int pi)
    {
        if (si == s.length() && pi == p.length())       //Matched, done.
            return 2;
        
        if (si == s.length() && p[pi] != '*')           //Not matched, period.
            return 0;

        if (pi == p.length())                           //Not matched, still ongoing.
            return 1;

        if (p[pi] == '*')                           // " abcda "
        {                                           // " a**a "
            if (pi + 1 < p.length() && p[pi + 1] == '*')    //Skip duplicates
            {
                return dfs(s, p, si, pi + 1);      
            }                                           
            for (int i = 0; i <= s.length() - si; i++)
            {
                int ret = dfs(s, p, si + i, pi + 1);
                if (ret != 1)
                    return ret;
            }
        }

        if (p[pi] == '?' || s[si] == p[pi])
        {
            return dfs(s, p, si + 1, pi + 1);
        }
        return 1;
    }

    static bool isMatch(std::string s, std::string p)
    {
        return dfs(s, p, 0, 0) > 1;        
    }
};