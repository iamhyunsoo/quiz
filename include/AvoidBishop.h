#include <queue>
#include <utility>
#include <vector>

/*
[Ex] 
n = 8, startRow = 5, startCol = 1,
endRow = 0, endCol = 5, bishopRow = 3, bishopCol = 3

The board has a size of 6 x 6.
A path goes from (5, 1) to (4, 3) to (2, 4) to (0, 5)
Answer = 3
*/

int moves(int n, int startRow, int startCol, int endRow, int endCol, int bishopRow, int bishopCol)
{
    std::vector<std::vector<int>> dirs       = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
    std::vector<std::vector<int>> bishopDirs = { {-1, 1}, {1, 1}, {1, -1}, {-1, -1} };
    std::set<std::pair<int, int>> visited;
    std::queue<std::pair<std::pair<int,int>, bool>> que;
    std::vector<std::vector<bool>> bishopAllPosition(n, std::vector<bool>(n, false));

    // Mark all possbile positions where bishop could go.
    for (int d = 0; d < 4; d++)
    {
        for (int b_i = bishopRow, b_j = bishopCol; (b_i >= 0) && (b_i < n) && (b_j >= 0) && (b_j < n); b_i += bishopDirs[d][0], b_j += bishopDirs[d][1])
        {
            bishopAllPosition[b_i][b_j] = true;
        }
    }
    
    int move{ 0 };
    que.push({ { startRow, startCol }, true });
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            auto pos = que.front();
            que.pop();

            if (pos.first.first == endRow && pos.first.second == endCol)
            {
                return move;
            }

            bool bishopAlive = true;
            if (pos.second)
            {
                if (bishopRow == pos.first.first && bishopCol == pos.first.second)
                {
                    bishopAlive = false;
                }
            }
            else
            {
                bishopAlive = false;
            }

            if (bishopAlive && bishopAllPosition[pos.first.first][pos.first.second])
            {
                continue;
            }

            if (visited.count({ pos.first.first, pos.first.second }))
            {
                continue;
            }
            visited.insert({ pos.first.first, pos.first.second });

            for (int d = 0; d < 8; d++)
            {
                int nextRow = pos.first.first  + dirs[d][0];
                int nextCol = pos.first.second + dirs[d][1];
                if ((nextRow >= 0) && (nextRow < n) && (nextCol >= 0) && (nextCol < n))
                {
                    que.push( { { nextRow, nextCol }, bishopAlive } );
                }
            }
        }
        move++;
    }
    return -1;
}
