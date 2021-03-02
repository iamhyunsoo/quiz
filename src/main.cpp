#include "LongestPalindrome.h"

#include <algorithm>
#include <iostream>
#include <string.h>


using namespace std;

#include <iostream>
#include <vector>
class Solution1{
public:
int myAtoi(string s) 
    {
        int ret {0};
        bool isNeg = false;
        for (const char&  x : s)
        { 
            if (x == 32)
            {
              continue;
            }
            else if (x == 45)
            {
                isNeg = true;
                continue;
            }
            else if(x < 48 && x > 57)
            {
                return isNeg ? ret * -1 : ret;
            }

            ret = ret * 10 + (x - 48);
        }

        return isNeg ? ret * -1 : ret;
    }
};
int main()
{
    std::vector<int> a{ 1,2, 3,4,5,6};
    if (2 == 3)
    {

    }
    else
    {
        cout << "sibal\n";
    }

    std::vector<int> b{ 3,4 };
    Solution1 s;
    cout << s.myAtoi(std::string("   234 sdf")) << endl;
}