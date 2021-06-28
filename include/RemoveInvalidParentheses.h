#include <algorithm>
#include <string>
#include <vector>

class Solution
{
public:
	std::vector<std::string> removeInvalidParentheses(std::string s)
	{
		std::vector<std::string> ret;
		help(0, 0, s, ret, "()");
		return ret;
	}
private:
	void help(int pos, int lastRemovePos, std::string s, std::vector<std::string>& ret, char sign[])
	{
		for (int i = pos, cnt = 0; i < s.length(); i++)
		{
			if (s[i] == sign[0])
			{
				cnt++;
			}
			else if (s[i] == sign[1])
			{
				cnt--;
			}
			
			if (cnt >= 0)
			{
				continue;
			}

			for (int j = lastRemovePos; j <= i; j++)
			{
				if (s[j] == sign[1] && (j == lastRemovePos || s[j - 1] != sign[1]))
				{
					help(i, j, s.substr(0, j) + s.substr(j + 1), ret, sign);
				}
			}
			return;
		}
		std::reverse(s.begin(), s.end());
		if (sign[1] == ')')
		{
			help(0, 0, s, ret, ")(");
		}
		else
		{
			ret.push_back(s);
		}
        return;
	}
};