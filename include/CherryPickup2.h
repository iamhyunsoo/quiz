#include <algorithm>
#incldue <vector>

#define TOPDOWN

#ifdef TOPDOWN
class Solution 
{
	std::vector<std::vector<std::vector<int>>> mDP;
	int mRow;
	int mCol;
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) 
	{
		mRow = grid.size();
		mCol = grid[0].size();	// Constraint: there is at least one row.

		// 3-dimensional array. arr[row][col][col]
		mDP.assign(mRow, std::vector<std::vector<int>>(mCol, std::vector<int>(mCol, -1)));
		return helper(0, 0, mCol -1, grid);
    }
private:
	int helper(int row, int col1, int col2, std::vector<std::vector<int>>& grid)
	{
		if (col1 < 0 || col2 < 0 || col1 >= mCol || col2 >= mCol)
		{
			return 0;
		}

		if (mDP[row][col1][col2] != -1)
		{
			return mDP[row][col1][col2];
		}

		int currSum = col1 == col2 ? grid[row][col1] : grid[row][col1] + grid[row][col2];

		if (row != mRow - 1)
		{
			int futureMax {0};
			for (int c1 = col1 -1; c1 <= col1 + 1; c1++)
			{
				for (int c2 = col2 - 1; c2 <= col2 + 1; c2++)
				{
					futureMax = std::max(futureMax, helper(row + 1, c1, c2, grid));
				}
			}
			currSum += futureMax;
		}

		mDP[row][col1][col2] = currSum;
		return mDP[row][col1][col2];
	}
};
#endif

#ifdef BOTTOMUP
class Solution 
{
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) 
	{
		int row = grid.size();
		int col = grid[0].size();	// Constraint: there is at least one row.

		// 3-dimensional array. arr[row][col][col]
		std::vector<std::vector<std::vector<int>>> dp(row, std::vector<std::vector<int>>(col, std::vector<int>(col, -1)));

		for (int r = row - 1; r >= 0; r--)
		{
			for (int c1 = 0; c1 < col; c1++)
			{
				for (int c2 = 0; c2 < col; c2++)
				{
					int currSum = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
					if (r != row - 1)
					{
						int futureMax{0};
						for (int next_c1 = c1 - 1; next_c1 <= c1 + 1; next_c1++)
						{
							for (int next_c2 = c2 - 1; next_c2 <= c2 + 1; next_c2++)
							{
								if (next_c1 >= 0 && next_c1 < col && next_c2 >= 0 && next_c2 < col)
								{
									futureMax = std::max(futureMax, dp[r + 1][next_c1][next_c2]);
								}
							}
						}
						currSum += futureMax;
					}
					dp[r][c1][c2] = currSum;
				}
			}
		}
		return dp[0][0][col - 1];
    }
};
#endif
