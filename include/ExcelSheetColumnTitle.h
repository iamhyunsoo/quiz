#include <algorithm>
#include <string>

std::string convertToTitle(int n)
{
    std::string ans {};
    while (n)
    {
        n--;
        ans += (n % 26) + 'A';
        n /= 26;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}