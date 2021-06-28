#include <vector>


class NumMatrix
{
public:
	NumMatrix(std::vector<std::vector<int>>& matrix) : mMatrix{ matrix } 
	{
		for (int i = 0; i < mMatrix.size(); i++)
		{	
			for (int j = 0; j < mMatrix[0].size(); j++)
			{
				mMatrix[i][j] += help(i - 1, j) + help(i, j - 1) - help(i - 1, j - 1);
			}
		}		
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return help(row2, col2) - help(row2, col1 - 1) - help(row1 - 1, col2) + help(row1 - 1, col1 - 1);
	}

private:
	int help(int p, int q)
	{
		return p >= 0 && q >= 0 ? mMatrix[p][q] : 0;
	}

private:
	std::vector<std::vector<int>> mMatrix;
};
