#include <algorithm>
#include <cctype>
#include <string>

bool isPalindrome(std::string s)
{
    if (s.length() == 1)
    {
        return true;
    }
    
    int j {0};
    for (char& c : s)
    {
        c = tolower(c);
        if (isalnum(c))
        {
            s[j++] = c;
        }
    }

    s.erase(s.begin() + j, s.end());

    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    return s == rev;   
}