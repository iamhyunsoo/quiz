#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <vector>

int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k)
{
	const int row = matrix.size();
	const int col = row ? matrix[0].size() : 0;
	int ans{ INT_MIN };
	for (int l = 0; l < col; l++)
	{
		std::vector<int> sums(row, 0);
		for (int r = l; r < col; r++)
		{
			for (int k = 0; k < row; k++)
			{
				sums[k] += matrix[k][r];
			}

			std::set<int> cumulative{ 0 };
			int tmpSum{ 0 };
			int curMax{ INT_MIN };
			for (auto const& sum : sums)
			{
				tmpSum += sum;
				auto it = cumulative.lower_bound(tmpSum - k);
				if (it != cumulative.end())
				{
					curMax = std::max(curMax, tmpSum - *it);
				}
				cumulative.insert(tmpSum);
			}
			ans = std::max(ans, curMax);
		}
	}
	return ans;
}
