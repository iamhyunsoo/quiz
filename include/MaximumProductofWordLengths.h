#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

int maxProduct(std::vector<std::string> &words)
{
	std::unordered_map<int, int> m;
	int ans {0};	
	int bit {0};
	
	for (auto const& word : words)
	{
		bit = 0;
		for (auto const& c : word)
		{
			bit |= 1 << c - 'a';
		}
		m[bit] = std::max( m[bit], static_cast<int>(word.size()) );
	}

	for (auto const& p : m)
	{
		for (auto const& q : m)
		{
			if (!(p.first & q.first))
			{
				ans = std::max( ans, p.second * q.second );	
			}
		}
	}
	return ans;
}