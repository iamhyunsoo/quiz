#include <algorithm>
#include <string>
#include <vector>
#define INT_MAX (2147483647)

int findRotateSteps(std::string ring, std::string key) 
{
	const int rLen = ring.length();
	const int kLen = key.length();

	std::vector< std::vector< int > > dp(kLen + 1, std::vector<int>(rLen, 0));

	for (int i = kLen - 1; i >= 0; i--)
	{
		for (int j = 0; j < rLen; j++)
		{
			dp[i][j] = INT_MAX;
			for (int k = 0; k < rLen; k++)
			{
				if (key[i] == ring[k])
				{
					int distance = std::abs(j - k);
					distance = std::min( distance, rLen - distance );
					dp[i][j] = std::min( dp[i][j], distance + dp[i + 1][k]);
				}
			}
		}
	}

	return dp[0][0] + kLen;
}