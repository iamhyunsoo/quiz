#include <algorithm>
#include <vector>

int nthUglyNumber(int n)
{
	int n2 {2};
	int n3 {3};
	int n5 {5};
	int i2 {0};
	int i3 {0};
	int i5 {0};
	int last {0};
	std::vector<int> v(n, 1);
	for (int i = 1; i < n; i++)
	{
		while (n2 <= last)
		{
			n2 = 2 * v[++i2];
		}
		while (n3 <= last)
		{
			n3 = 3 * v[++i3];
		}
		while (n5 <= last)
		{
			n5 = 5 * v[++i5];
		}
		v[i] = last = std::min(n2, std::min(n3, n5));		
	}
	return v[n - 1];
}