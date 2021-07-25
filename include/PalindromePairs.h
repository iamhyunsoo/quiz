#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>


class Solution
{
public:
	std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words)
	{
		std::unordered_map<std::string, int> m;
		std::vector<std::vector<int>> ret;

		for (int i = 0; i < words.size(); i++)
		{
			std::string key = words[i];
			std::reverse(key.begin(), key.end());
			m[key] = i;
		}

		if (m.find("") != m.end())
		{
			for (int i = 0; i < words.size(); i++)
			{
				if (i == m[""]) continue;
				if (isPalindrome(words[i]))
				{
					ret.push_back({m[""], i});
				}
			}
		}

		for (int i = 0; i < words.size(); i++)
		{
			auto& refWord = words[i];
			for (int j = 0; j < refWord.size(); j++)
			{
				std::string l = refWord.substr(0, j);
				std::string r = refWord.substr(j, refWord.size() - j);

				if (m.find(l) != m.end() && isPalindrome(r) && m[l] != i)
				{
					ret.push_back({i, m[l]}); 
				}

				if (m.find(r) != m.end() && isPalindrome(l) && m[r] != i)
				{
					ret.push_back({m[r], i});
				}
			}
		}

		return ret;
	}

private:
	bool isPalindrome(std::string str)
	{
		int i = 0;
		int j = str.size() - 1;
		while (i < j)
		{
			if (str[i++] != str[j--])
			{
				return false;
			}
		}
		return true;
	}
};