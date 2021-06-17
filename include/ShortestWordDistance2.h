#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#define INT_MAX (2147483647)
using std::string;
using std::unordered_map;
using std::vector;

class WordDistance
{
public:
	WordDistance(vector<string> words)
	{
		for (int i = 0; i < words.size(); i++)
		{
			mMap[words[i]].push_back(i);
		}
	}

	int shortestDistance(string word1, string word2)
	{
		vector<int> idx1 = mMap.find(word1) != mMap.end() ? mMap[word1] : vector<int>{};
		vector<int> idx2 = mMap.find(word2) != mMap.end() ? mMap[word2] : vector<int>{};
		if (idx1.empty() || idx2.empty()) 
			return INT_MAX;	

		int ans {INT_MAX};
		int i {0};
		int j {0};
		while (i < idx1.size() && j < idx2.size())
		{
			ans = std::min(ans, std::abs(idx1[i] - idx2[j]));
			if (idx1[i] < idx2[j])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		return ans;
	}

private:
	unordered_map<string, vector<int>> mMap;
};