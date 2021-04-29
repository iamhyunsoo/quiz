#include <algorithm>
#include <vector>
//      2               0
//    3   4             1
//   6  5  7            2
//  4  1  8  3          3

int minimumTotal(std::vector< std::vector<int> >& triangle)     
{    
    int size = triangle.size();
    int level = size - 1;                                                               
    std::vector< std::vector<int> > dp(2, std::vector<int>(size, 0));                                                            

    dp[level-- & 1] = triangle[size - 1];

    for (; level >= 0; level--)
    {
        for (int i = 0; i <= level; i++)
        {
            dp[level & 1][i] = triangle[level][i] + std::min( dp[ (level + 1) & 1 ][i], dp[ (level + 1) & 1 ][i + 1] );
        }
    }
    return dp[0][0];
}

int minimumTotal2(std::vector< std::vector<int> >& triangle)
{
    int size = triangle.size();
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] = triangle[i][j] + std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

