class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] += std::min(matrix[i-1][j], 
                                        std::min(j == 0 ? INT_MAX : matrix[i - 1][j - 1], 
                                                 j == matrix[0].size() - 1 ? INT_MAX : matrix[i - 1][j + 1]));
            }
        }
        return *std::min_element(matrix.back().begin(), matrix.back().end());
    }
};
