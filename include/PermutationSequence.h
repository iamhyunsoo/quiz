#include <algorithm>
#include <string>

class Solution 
{
public:
    std::string getPermutation(int n, int k)
    {
        int fac = 1;
        std::string ans {};
        for (int i = 1; i <= n; i++)
        {
            fac *= i;
            ans += (char)(i + '0');
        }
        if (k == fac)
        {
            std::reverse(ans.begin(), ans.end());
            return ans;
        }
        else if (k == 1)
        {
            return ans;
        }
        else
        {
            int r {-1};     //Just temporary first remainder to avoid while loop condition first time.
            int i {0};      //Current string position [0, 1, 2, 3, 4 . . . .]
            while (r != 0)
            {
                fac /= n--;
                r = k % fac;
                k = (k / fac) + (r == 0 ? -1 : 0);      //if remainder(r) is 0, it should swap current position with (current position + quotient - 1) " minus 1 is important here"
                if (k != 0)
                {
                    std::swap(ans[i], ans[i + k]);
                    std::sort(ans.begin() + i + 1, ans.end());
                }
                if ( r == 0 )
                {
                    std::reverse(ans.begin() + i + 1, ans.end());
                }
                k = r;
                i++;
            }
        }
        return ans;
    }
};