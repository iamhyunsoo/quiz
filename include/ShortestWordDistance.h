#include <algorithm>
#include <string>
#include <vector>

#define INT_MAX (2147483647)
using std::string;
using std::vector;

int shortestDistance(vector<string>& words, string word1, string word2)
{
	int index1 {-1};
	int index2 {-1};
	int ans {INT_MAX};
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == word1)
		{
			index1 = i;
		}
		else if (words[i] == word2)
		{
			index2 = i;
		}
		
		if (index1 != -1 && index2 != -1)
		{
			ans = std::min(ans, std::abs(index1 - index2));
		}
	}
	return ans;
}