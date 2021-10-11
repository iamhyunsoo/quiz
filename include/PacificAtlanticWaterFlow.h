class Solution
{
private:
	int mRow;
	int mCol;
	std::vector<std::vector<int>> mRet;
	std::vector<std::vector<bool>> mPac;
	std::vector<std::vector<bool>> mAtl;

public:
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix)
	{
		mRow = matrix.size();
		mCol = mRow ? matrix[0].size() : 0;
		mPac = std::vector<std::vector<bool>>(mRow, std::vector<bool>(mCol, 0));
		mAtl = std::vector<std::vector<bool>>(mRow, std::vector<bool>(mCol, 0));

		for (int i = 0; i < mRow; i++)
		{
			help(matrix, mPac, i, 0);
			help(matrix, mAtl, i, mCol - 1);
		}

		for (int i = 0; i < mCol; i++)
		{
			help(matrix, mPac, 0, i);
			help(matrix, mAtl, mRow - 1, i);
		}

		return mRet;
	}
private:
	void help(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& ocean, int i, int j)
	{
		if (ocean[i][j]) { return; }

		ocean[i][j] = true;

		if (mPac[i][j] && mAtl[i][j])
		{
			mRet.push_back(std::vector<int>{i, j});
		}

		if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j])
		{
			help(matrix, ocean, i - 1, j);
		}
		if (j + 1 < mCol && matrix[i][j + 1] >= matrix[i][j])
		{
			help(matrix, ocean, i, j + 1);
		}
		if (i + 1 < mRow && matrix[i + 1][j] >= matrix[i][j])
		{
			help(matrix, ocean, i + 1, j);
		}
		if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j])
		{
			help(matrix, ocean, i, j - 1);
		}
	}
};
