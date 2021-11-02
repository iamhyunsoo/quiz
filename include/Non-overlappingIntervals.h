#include <algorithm>
#include <vector>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) 
{
	std::sort(intervals.begin(), intervals.end(), 
	[](std::vector<int> const& a, std::vector<int> const& b) 
	{
			return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	});

	int ret{ 0 };
	int prev{ 0 };
	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[prev][1] > intervals[i][0])
		{
			ret++;
			if (intervals[prev][1] > intervals[i][1])
			{
				prev = i;
			}
		}
		else
		{
			prev = i;
		}
	}

	return ret;
}
