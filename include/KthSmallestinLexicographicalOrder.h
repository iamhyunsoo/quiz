#include <algorithm>

int findKthNumber(int n, int k) 
{
	int ret {1};
	for (--k; k > 0;)
	{	
		int cnt {0};
		for (long start = ret, end = start+1; start <= n; start *= 10, end *= 10)
		{
			cnt += (std::min(static_cast<int>(n)+1L, end) - start);
		}

		if (k >= cnt)
		{
			ret++;
			k -= cnt;
		}
		else
		{
			ret *= 10;
			k--;
		}
	}
	return ret;
}