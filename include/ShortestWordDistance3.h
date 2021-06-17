#include <algorithm>
#include <string>
#include <vector>

#define INT_MAX (2147483647)
using std::string;
using std::vector;

int shortestWordDistance(vector<string>& words, string word1, string word2)
{
	int idx1 {-1};
	int idx2 {-1};
	int ans {INT_MAX};

	for (int i = 0; i < words.size(); i++)
	{
		if (word1 == word2)
		{
			if (idx1 > idx2)
			{
				idx2 = i;
			}
			else
			{
				idx1 = i;
			}
		}
		else
		{
			if (words[i] == word1) 
				idx1 = i;
			else if (words[i] == word2) 
				idx2 = i;
		}

		if (idx1 != -1 && idx2 != -1)
		{
			ans = std::min( ans, std::abs(idx1 - idx2));
		}
	}
	return ans;
}