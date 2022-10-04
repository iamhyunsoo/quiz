class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dirs[] = {0, 1, 0, -1, 0};
        int m = grid.size();
        int n = grid[0].size();
    
        // < step, row, col, remainingK >
        std::queue<std::tuple<int, int, int, int>> q;
        std::vector<int> visited(m*n, -1);

        q.push({0, 0, 0, k});
        visited[0] = k;
        
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int step = std::get<0>(front);
            int row = std::get<1>(front);
            int col = std::get<2>(front);
            int k = std::get<3>(front);
            if (row == m -1 && col == n - 1)
            {
                return step; 
            }
            for (int i = 0; i < 4; ++i)
            {
                int r = row + dirs[i];
                int c = col + dirs[i + 1];
                int newStep = step + 1;
                if (r < 0 || r >= m || c < 0 || c >= n) { continue; }
                int newK = k - grid[r][c];
                if (visited[r*n + c] >= newK) { continue; }
                if (newK >= 0)
                {
                    visited[r*n + c] = newK;
                    q.push({newStep, r, c, newK});
                }
            }
        }
        return -1;
    }
};
