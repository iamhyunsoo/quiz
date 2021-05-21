#include <algorithm>
#include <vector>

using std::vector;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    const int row = dungeon.size();
    const int col = dungeon[0].size();
                                                                     // I was lazy..
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 21000000)); //21000000 should be INT_MAX
    dp[row][col - 1] = 1;
    dp[row - 1][col] = 1;

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int val = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] =  val <= 0 ? 1 : val;
        }
    }
    return dp[0][0];
}