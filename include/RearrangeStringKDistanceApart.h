#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::string rearrangeString(std::string str, int k)
{
	std::unordered_map<char, int> dict;
	std::priority_queue<std::pair<char, int>> q;
	
	for (char const& c : str)
	{
		dict[c]++;
	}
	for (auto& p : dict)
	{
		q.push(p);
	}
	
	int len = str.length();
	std::string ret{ "" };

	while (!q.empty())
	{
		int limit = std::min(k, len);
		std::vector<std::pair<char, int>> v;
		for (int i = 0; i < limit; i++)
		{
			if (q.empty())
			{
				return "";
			}

			auto p = q.top();
			q.pop();

			ret += p.first;
			if (--p.second > 0)
			{
				v.push_back(p);
			}
			--len;
		}

		for (auto& p : v)
		{
			q.push(p);
		}
	}

	return ret;
}
