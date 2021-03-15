#include <string>

int StrStr(const std::string& haystack, const std::string& needle)
{
    if (needle.length() == 0)
        return 0;
    
    int i {0};
    int j {0};
    int needleSize = needle.length();
    for (; i < haystack.length(); i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
        }
        else
        {
            i -= j;
            j = 0;
        }

        if (j == needleSize)
        {
            return i - j + 1;
        }
    }
    return -1;
}