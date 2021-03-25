#include <algorithm>
#include <vector>
std::vector< std::vector< int > > ThreeSum(std::vector<int> vec)
{
	std::vector< std::vector< int > > ret;
	int size = vec.size();
	if (size == 0 || (size == 1 && vec[0] == 0))
	{
		return ret; //
	}
	
	std::sort(vec.begin(), vec.end());

	int l{ 0 };
	int r{ 0 };
	for (int i = 0; i < size; i++)
	{
		if (i > 0 && vec[i] == vec[i - 1])
		{
			continue;
		}
        
        l = i + 1;
		r = size - 1;

		while (l < r)
		{
			if (vec[i] + vec[l] + vec[r] > 0)
			{
				--r;
			}
			else if (vec[i] + vec[l] + vec[r] < 0)
			{
				++l;
			}
			else
			{
				ret.emplace_back(std::vector<int>{vec[i], vec[l], vec[r]});
				++l;

				while (vec[l] == vec[l - 1] && l < r)
				{
					++l;
				}
			}
		}
	}
	return ret;
}
