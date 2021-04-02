#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    
    if(obstacleGrid[0][0]==1) 
        return 0;
    if (n == 1 && m == 1)
        return 1;

    int i{1};
    int j{1};

    while (i < n && obstacleGrid[i][0] != 1)
    {
        obstacleGrid[i][0] = 1;
        i++;
    }
    while (i < n)
    {
        obstacleGrid[i][0] = 0;
        i++;
    }
    while (j < m && obstacleGrid[0][j] != 1)
    {
        obstacleGrid[0][j] = 1;
        j++;
    }
    while (j < m)
    {
        obstacleGrid[0][j] = 0;
        j++;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(obstacleGrid[i][j]==1) 
            {
                obstacleGrid[i][j]=0;
                continue;
            }
            else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        }
    }
    return obstacleGrid[n-1][m-1];
}