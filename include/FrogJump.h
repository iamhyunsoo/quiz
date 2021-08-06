
#include <vector>
bool canCross(std::vector<int>& stones) 
{
	int size = stones.size();
	std::vector<std::vector<bool>> dp(size, std::vector<bool>(size + 1, false));

	dp[0][1] = true;
	int dist{ 0 };
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dist = stones[i] - stones[j];
			if (dist < 0 || dist > size || !dp[j][dist])
			{
				continue;
			}
			dp[i][dist] = true;
			if (dist - 1 >= 0)
			{
				dp[i][dist - 1] = true;
			}
			if (dist + 1 <= size)
			{
				dp[i][dist + 1] = true;
			}
			if (i == size - 1)
			{
				return true;
			}
		}
	}
	return false;
}
