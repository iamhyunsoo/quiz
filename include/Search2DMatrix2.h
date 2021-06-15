#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{	
	int rows = matrix.size();
	int cols = rows ? matrix[0].size() : 0;
	int r = 0;
	int c = cols - 1;

	while (r < rows && c >= 0)
	{
		if (matrix[r][c] == target)
		{
			return true;
		}
		matrix[r][c] > target ? c-- : r++;
	}
	return false;
}