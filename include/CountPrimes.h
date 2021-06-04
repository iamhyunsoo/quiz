#include <cmath>
#include <vector>

int countPrimes(int n)
{
    if (n < 2)
    { return 0; }

    std::vector<bool> v(n + 1, false);
    for (int i = 2; i <= (int)std::sqrt(n); i++)
    {
        if (!v[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                v[j] = true;
            }
        }
    }

    int ans {0};
    for (int i = 2; i < n; i++)
    {
        if (!v[i])
        {
            ans++;
        }
    }
    return ans;
}