class Solution 
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        const int row = grid.size();
        const int col = row ? grid[0].size() : 0;
        std::vector<int> rowMax(row, 0);
        std::vector<int> colMax(col, 0);
        int sum {0};
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                rowMax[i] = std::max(rowMax[i], grid[i][j]);
                colMax[j] = std::max(colMax[j], grid[i][j]);
            }
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += (std::min(rowMax[i], colMax[j]) - grid[i][j]);
            }
        }
        return sum;
    }
};
