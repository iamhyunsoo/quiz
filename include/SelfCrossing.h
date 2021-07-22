#include <vector>

bool isSelfCrossing(std::vector<int>& distance) 
{
	int a {0};
	int b {0};
	int c {0};
	int d {0};
	int e {0};
	int f {0};

	for (const auto& x : distance)
	{
		f = e;
		e = d;
		d = c;
		c = b; 
		b = a;
		a = x;
		
		if (b <= d && b > 0 && (a >= c || (c >= e && (c-e) <= a && b >=(d-f))))
			return true;
	}

	return false;
}