#include <utility>
#include <queue>
#include <vector>

using std::vector;

class Solution 
{
public:
    int numIslandsBFS(vector<vector<char>>& grid)  //BFS
    {
        const int row = grid.size();
        const int col = grid[0].size();
        int islands {0};
        int routes[5] = {0, 1, 0, -1, 0};
        std::queue<std::pair<int,int>> que;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '0';
                    que.push({i, j});

                    while (!que.empty())
                    {
                        auto tmp = que.front();
                        que.pop();

                        for(int k = 0; k < 4; k++)
                        {
                            int r = tmp.first + routes[k];
                            int c = tmp.second+ routes[k + 1];
                            if (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == '1')
                            {
                                grid[r][c] = '0';
                                que.push({r, c});
                            }
                        }
                    }
                }
            }
        }        

        return islands;
    }

public:
    int numIslandsDFS(vector<vector<char>>& grid)  //DFS
    {
        const int row = grid.size();
        const int col = grid[0].size();
        int islands {0};

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    help(grid, i, j, row, col);
                }
            }
        }        

        return islands;
    }
private:
    void help(vector<vector<char>>& grid, int r, int c, const int& row, const int& col)
    {
        if (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == '1')
        {
            grid[r][c] = '0';
            help(grid, r, c + 1, row, col);
            help(grid, r + 1, c, row, col);
            help(grid, r, c - 1, row, col);
            help(grid, r - 1, c, row, col);
        }
        else
        {
            return;
        }
    }
};