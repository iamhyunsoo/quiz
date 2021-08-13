#include <algorithm>
#include <unordered_map>

class Solution 
{
public:
    int integerReplacement(int n) 
    {
        if (n == 1)
        {
            return 0;
        }
        while (mMap[n] == 0)
        {
            if (n & 1 == 1)
            {
                mMap[n] = 2 + std::min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            }
            else
            {
                mMap[n] = 1 + integerReplacement(n / 2);
            }
        }
        return mMap[n];
    }
private:
    std::unordered_map<int, int> mMap;
};
