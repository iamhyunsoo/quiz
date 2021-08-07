#include <cmath>
#include <string>
#include <vector>

std::vector<std::string> generateAbbreviations(std::string word)
{
	std::vector<std::string> ret;
	int len = word.length();
	for (int i = 0; i < std::pow(2, len); i++)
	{
		int cnt = 0;
		std::string tempStr = "";
		for (int j = 0; j < len; j++)
		{
			if ((i >> j) & 1)
			{
				cnt++;
			}
			else
			{
				if (cnt)
				{
					tempStr += std::to_string(cnt);
					cnt = 0;
				}
				tempStr += word[j];
			}
		}
		if (cnt)
		{
			tempStr += std::to_string(cnt);
		}
		ret.push_back(tempStr);
	}
	return ret;
}