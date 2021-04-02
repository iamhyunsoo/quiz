#include <vector>

int uniquePath(int m, int n)
{
    std::vector< std::vector<int> > vec(m, std::vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                vec[i][j] = 1;
            }
            else if (i == 0)
            {
                vec[i][j] = vec[i][j-1];
            }
            else if (j == 0)
            {
                vec[i][j] = vec[i-1][j];
            }
            else
            {
                vec[i][j] = vec[i-1][j] + vec[i][j-1];
            }
        }
    }
    return vec[m-1][n-1];
}