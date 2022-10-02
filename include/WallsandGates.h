class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        int GATE = 0;
        int EMPTY = 2147483647;
        int dirs[] = {0, 1, 0, -1, 0};
        std::queue<std::vector<int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rooms[i][j] == GATE)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int r = front[0];
            int c = front[1];
            for (int i = 0; i < 4; ++i)
            {
                int newR = r + dirs[i];
                int newC = c + dirs[i + 1];
                if (newR < 0 || newR >= m || newC < 0 || newC >= n || rooms[newR][newC] != EMPTY)
                {
                    continue;
                }
                rooms[newR][newC] = rooms[r][c] + 1;
                q.push({ newR, newC });
            }
        }
    }
};
