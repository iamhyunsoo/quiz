class Solution5934 
{
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        mRow = maze.size();
        mCol = mRow ? maze[0].size() : 0;
        mVisited.assign(mRow, std::vector<bool>(mCol, false));
   
        return dfs(start[0], start[1], maze, destination);
    }

    bool dfs(int i, int j, vector<vector<int>>& maze, vector<int>& destination)
    {
        if (mVisited[i][j]) return false;
        if (i == destination[0] && j == destination[1]) return true;

        mVisited[i][j] = true; 
        for (auto const& dir : mDirs)
        {
            int nextRow = i;
            int nextCol = j;
            while (nextRow >= 0 && nextRow < mRow && nextCol >= 0 && nextCol < mCol && maze[nextRow][nextCol] == 0)
            {
                nextRow += dir[0];
                nextCol += dir[1];
            }
            nextRow -= dir[0];
            nextCol -= dir[1];

            if (!mVisited[nextRow][nextCol] && dfs(nextRow, nextCol, maze, destination))
            {
                return true;
            }
        }
        return false;
    }

private:
    int mRow;
    int mCol;
    vector<vector<bool>> mVisited;
    vector<vector<int>> mDirs = { {1,0}, {0,1}, {-1,0}, {0,-1} };
};
