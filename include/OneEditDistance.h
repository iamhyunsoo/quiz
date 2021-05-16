#include <cmath>
#include <string>
#include <algorithm>

bool isOneEditDistance(std::string s, std::string t)
{
    int len1 = s.length();
    int len2 = t.length();

    if (std::abs(len1 - len2) > 1)
    {
        return false;
    }

    if (len1 < len2)
    {
        std::swap(len1, len2);
    }

    for (int i = 0; i < len1; i++)
    {
        if (s[i] != t[i])
        {
            if (len1 == len2)
            {
                return s.substr(i + 1) == t.substr(i + 1);
            }
            return s.substr(i + 1) == t.substr(i);
        }
    }

    return false;
}