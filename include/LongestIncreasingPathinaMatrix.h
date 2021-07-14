#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

class Solution
{
public:
	int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
	{
		int cnt {INT_MIN};
		int row = matrix.size();
		int col = row ? matrix[0].size() : 0;
		this->dp.resize(row, std::vector<int>(col, 0));

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cnt = std::max(cnt, help(matrix, i, j, row, col, -1));
			}
		}
		return cnt;
	}

private:
	int help(std::vector<std::vector<int>>& matrix, int i, int j, int& row, int& col, int num)
	{
		if (i < 0 || i >= row || j < 0 || j >= col || num >= matrix[i][j])
		{
			return 0;
		}

		if (this->dp[i][j])
		{
			return dp[i][j];
		}

		int up    = help(matrix, i + 1, j, row, col, matrix[i][j]);
		int right = help(matrix, i, j + 1, row, col, matrix[i][j]);
		int down  = help(matrix, i - 1, j, row, col, matrix[i][j]);
		int left  = help(matrix, i, j - 1, row, col, matrix[i][j]);

		return this->dp[i][j] = std::max({up, down, right, left}) + 1;
	}

private:
	std::vector<std::vector<int>> dp;
};