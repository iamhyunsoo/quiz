#include <algorithm>
#include <cmath>
#include <string>


int titleToNumber(std::string columnTitle) 
{
    int ans {0};
    for (int i = 0; i < columnTitle.length(); i++)
    {
        ans = ans * 26 + (columnTitle[i] - 'A' + 1);
    }
    return ans;
}

int titleToNumber(std::string s) //Using pow function
{
    int col = 0;
    for(int i = s.length(); i > 0; i--) 
    {
        col += (s[i - 1] - 'A' + 1) * pow(26, (s.length() - i));
    }
    return col;
}