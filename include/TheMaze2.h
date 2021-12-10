class Solution
{
public:
    int shortestDistance(vector<vector<int>> maze, vector<int> start, vector<int> destination)
     {
        mRow = maze.size();
        mCol = mRow ? maze[0].size() : 0;
        mDistance.assign(mRow, std::vector<int>(mCol, INT_MAX));
        mDistance[start[0]][start[1]] = 0;
        dfs(start[0], start[1], maze, destination);
        return mDistance[destination[0]][destination[1]] == INT_MAX ? -1 : mDistance[destination[0]][destination[1]];
    }

    void dfs(int i, int j, vector<vector<int>>& maze, vector<int>& destination)
    {
        for (auto const& dir : mDirs)
        {
            int tmpDistance = 0;
            int nextRow = i + dir[0];
            int nextCol = j + dir[1];

            while (nextRow >= 0 && nextRow < mRow && nextCol >= 0 && nextCol < mCol && maze[nextRow][nextCol] == 0)
            {
                tmpDistance++;
                nextRow += dir[0];
                nextCol += dir[1];
            }
            nextRow -= dir[0];
            nextCol -= dir[1];

            if (mDistance[i][j] + tmpDistance < mDistance[nextRow][nextCol])
            {
                mDistance[nextRow][nextCol] = mDistance[i][j] + tmpDistance;
                dfs(nextRow, nextCol, maze, destination);
            }
        }
        return;
    }

private:
    int mRow;
    int mCol;
    vector<vector<int>> mDistance;
    vector<vector<int>> mDirs = { {1,0}, {0,1}, {-1,0}, {0,-1} };
};
