
int trapRainWater(vector<vector<int>> heightMap) 
{
    const int row = heightMap.size();
    const int col = row ? heightMap[0].size() : 0;
    
    int sum{ 0 };
    int curMax{ 0 };
    
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>> > que;
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, 0));
    std::vector<std::vector<int>> dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1 } };

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i != 0) && (i != row - 1) && (j != 0) && (j != col - 1)) 
            { 
                continue; 
            }
         
            que.push({ heightMap[i][j], i * col + j });
            visited[i][j] = true;
        }
    }

    while (!que.empty())
    {
        std::pair<int, int> p = que.top();
        que.pop();

        curMax = std::max(curMax, p.first);

        int i = p.second / col;
        int j = p.second % col;
        
        for (std::vector<int> const& dir : dirs)
        {
            int x = i + dir[0];
            int y = j + dir[1];

            if ((x < 0) || (x >= row) || (y < 0) || (y >= col) || visited[x][y])
            {
                continue;
            }
            
            if (heightMap[x][y] < curMax)
            {
                sum += (curMax - heightMap[x][y]);
            }

            que.push( { heightMap[x][y], x * col + y } );
            visited[x][y] = true;
        }
    }

    return sum;
}
