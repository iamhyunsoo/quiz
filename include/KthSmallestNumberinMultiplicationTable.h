#include <algorithm>

class Solution
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        int l = 1;
        int r = m * n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int cnt = SmallerOrEqualTo(mid, m, n);

            if (cnt >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }

private:
    int SmallerOrEqualTo(int mid, int m, int n)
    {
        int ret{ 0 };
        for (int i = 1; i <= m; i++)
        {
            ret += std::min(n, mid / i);
        }
        return ret;
    }
};
