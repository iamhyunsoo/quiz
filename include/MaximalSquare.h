#include <algorithm>
#include <vector>

using std::vector;

int maximalSquare2D(vector<vector<char>>& matrix) // 2D dp
{
    const int row = matrix.size();
    const int col = row ? matrix[0].size() : 0;
    vector< vector< int > > dp(row + 1, vector<int>(col + 1, 0));
    int maxLen {0}; 

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (matrix[i-1][j-1] == '1')
            {
                dp[i][j] = std::min( std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1] );
                maxLen = std::max( maxLen, dp[i][j]);
            }
        }
    }
    return maxLen * maxLen;
}

int maximalSquare1D(vector<vector<char>>& matrix) // 1D dp
{
    const int row = matrix.size();
    const int col = row ? matrix[0].size() : 0;
    vector<int> dp(col + 1, 0);
    int maxLen {0}; 
    int prev {0};

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            int tmp = dp[j];
            if (matrix[i-1][j-1] == '1')
            {
                dp[j] = std::min( std::min( dp[j - 1] , dp[j] ), prev ) + 1;
                maxLen = std::max( maxLen, dp[j] );
            }
            else
            {
                dp[j] = 0;
            }
            prev = tmp;
        }
    }
    return maxLen * maxLen;
}
