#include <cmath>

class Solution441
{
public:
	int arrangeCoins(int n)
	{
		int cnt{ 0 };
		int l{ 0 };
		int h = std::pow(2, 16);

		while (l <= h)
		{
			int m = (l + h) / 2;

			if (help(n, m))
			{
				cnt = m;
				l = m + 1;
			}
			else
			{
				h = m - 1;
			}
		}
		return cnt;
	}

	bool help(int n, long mid)
	{
		long maxCoins = (mid * (mid + 1)) / 2;
		return maxCoins <= n;
	}
};
