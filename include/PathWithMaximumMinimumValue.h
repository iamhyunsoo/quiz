int maximumMinimumPath(std::vector<std::vector<int>>& grid) 
{
    int row = grid.size();
    int col = row ? grid[0].size() : 0;		
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        std::priority_queue<std::pair<int, std::pair<int,int>>> que;
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));

    visited[0][0] = true;
    que.push({grid[0][0], {0, 0}});
    int maxMin = grid[0][0];

    while (!que.empty())
    {
      auto top = que.top();
      que.pop();

      int curVal = top.first;
      int curRow = top.second.first;
      int curCol = top.second.second;
      maxMin = std::min(maxMin, curVal);

      if (curRow == row - 1 && curCol == col - 1)
      {
        break;
      }

      for (auto const& dir : dirs)
      {
        auto nextRow = curRow + dir[0];
        auto nextCol = curCol + dir[1];
        if (nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && !visited[nextRow][nextCol])
        {
          que.push({grid[nextRow][nextCol], {nextRow, nextCol}});
          visited[nextRow][nextCol] = true;
        }
      }
    }
    return maxMin;
}
