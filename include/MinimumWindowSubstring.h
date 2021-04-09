#include <string>
#include <unordered_map>

//" asdffghjkl " , " hkl " 
std::string minWindow(std::string s, std::string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return "";
    }

    std::unordered_map<char, int> map;
    for (const char& x : t)
    {
        map[x]++;
    }

    int minLength {2147483647}; //should be maximum of signed 4 bytes, which is probably 2,147,483,647
    int minStart {0};
    int count {0};
    int l {0};
    int r {0};

    int tLen = t.length();
    
    for (; r < s.length(); r++)
    {
        if (map[s[r]] > 0)
        {
            count++;
        }
        map[s[r]]--;

        if (count == tLen)
        {
            while (l < r && map[s[l]] < 0)
            {
                map[s[l]]++;
                l++;
            }
            if (minLength > (r - l))
            {
                minLength = (r - l + 1);
                minStart  = l;
            }
            map[s[l]]++;
            l++;
            count--;
        }
    }
    return minLength == 2147483647 ? "" : s.substr(minStart, minLength);
}