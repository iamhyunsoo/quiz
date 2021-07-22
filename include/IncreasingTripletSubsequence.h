#include <bits/stdc++.h>
#include <vector>

bool increasingTriplet(std::vector<int> &nums)
{
	int first {INT_MAX};
	int second {INT_MAX};

	for (auto const& num : nums)
	{
		if (num <= first)
		{
			first = num;
		}
		else if (num <= second)
		{
			second = num;
		}
		else
		{
			return true;
		}
	}
	return false;
}