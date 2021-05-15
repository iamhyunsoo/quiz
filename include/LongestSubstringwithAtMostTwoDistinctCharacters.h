#include <algorithm>
#include <string>
#include <map>

int lengthOfLongestSubstringTwoDistinct(std::string s)
{
    int idx {0};
    int start {0};
    const int len = s.length();
    std::map<char, int> map;
    int ans {0};
    while (idx < len)
    {
        map[s[idx]] = idx;
        idx++;

        if (map.size() > 2)
        {
            int leftest = len;
            for (auto& m : map)
            {
                leftest = std::min(leftest, m.second);
            }
            map.erase(s[leftest]);
            start = leftest + 1;
        }

        ans = std::max(ans, idx - start);
    }
    return ans;
}