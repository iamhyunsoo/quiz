#include <algorithm>
#include <string>
#include <vector>

std::string shortestPalindrome(std::string s)
{
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    std::string l = s + "@" + rev;  

    std::vector<int> v(l.size(), 0);

    for (int i = 1; i < l.length(); i++)
    {
        int j = v[i - 1];   
        while (j > 0 && l[j] != l[i])
        {
            j = v[j - 1];
        }
        v[i] = ( j += ( l[j] == l[i] ) );
    }
    return rev.substr(0, rev.length() - v[l.length()-1]) + s;
}

/*
acecaa

000011


acecaa & aaceca

0,0,0,0,0,0, 0, 0,0,0,0,0,0

0,0,0,0,1,1, 0, 1,1,2,3,4,5

*/