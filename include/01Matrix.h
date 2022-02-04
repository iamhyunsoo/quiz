std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& matrix)
{
    int row = matrix.size();
    if (!row) return {};
    int col = matrix[0].size();

    std::vector<std::vector<int>> dp(row, std::vector<int>(col, INT_MAX- 10000));
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (!matrix[r][c]) 
            { 
                dp[r][c] = 0; 
            }
            else
            {
                if (r > 0)
                {
                    dp[r][c] = std::min(dp[r][c], dp[r - 1][c] + 1);
                }
                if (c > 0)
                {
                    dp[r][c] = std::min(dp[r][c], dp[r][c - 1] + 1);
                }
            }
        }
    }
    for (int r = row - 1; r >= 0; r--)
    {
        for (int c = col - 1; c >= 0; c--)
        {
            if (!matrix[r][c]) 
            { 
                dp[r][c] = 0; 
            }
            else
            {
                if (r < row - 1)
                {
                    dp[r][c] = std::min(dp[r][c], dp[r + 1][c] + 1);
                }
                if (c < col - 1)
                {
                    dp[r][c] = std::min(dp[r][c], dp[r][c + 1] + 1);
                }
            }
        }
    }
    return dp;
}
