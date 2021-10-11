#include <algorithm>
#include <string>
#include <vector>

int characterReplacement(std::string s, int k)
{
	std::vector<int> freq(26, 0);
	int len = s.length();
	int start {0};
	int maxCnt {0};

	for (int i = 0; i < len; i++)
	{
		maxCnt = std::max(maxCnt, ++freq[s[i] - 'A']);
		if (maxCnt + k <= i - start)
		{
			--freq[s[start++] - 'A'];
		} 
	}
	return len - start;
}