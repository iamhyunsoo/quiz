#include <vector>

std::vector<int> countBits(int n)
{
	std::vector<int> ret(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		ret[i] = ret[i & (i - 1)] + 1;
	}
	return ret;
}
