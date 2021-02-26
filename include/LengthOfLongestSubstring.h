#include <algorithm>
#include <map>
#include <string>

int LengthOfLongestSubstring(std::string s)
{
    int left {0};
    int len  {0};
    std::map<const char, int> m;
    for (int right = 0; left + len < static_cast<int>(s.size()); ++right)
    {
        if (m.find(s[right]) != m.end())
        {
            left = std::max(left, m[s[right]] + 1);
        }
        m[s[right]] = right;
        len = std::max(len, right - left + 1);
    }
    return len;
}
