#include <vector>

class S
{
public:
    int numberOfPatterns(int m, int n)
    {
        int ret{ 0 };
        std::vector<std::vector<int>> jumps(10, std::vector<int>(10, 0));
        std::vector<int> visited(10, false);
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;

        ret += help(1, 1, m, n, jumps, visited) * 4;
        ret += help(2, 1, m, n, jumps, visited) * 4;
        ret += help(5, 1, m, n, jumps, visited);

        return ret;
    }
private:
    int help(int num, int len, int m, int n, std::vector<std::vector<int>>& jumps, std::vector<int>& visited)
    {
        int ret{ 0 };
        if (len >= m)
        {
            ret++;
        }

        len++;

        if (len > n)
        {
            return ret;
        }

        visited[num] = true;

        for (int next = 1; next <= 9; next++)
        {
            int jump = jumps[num][next];
            if (!visited[next] && (!jump || visited[jump]))
            {
                ret += help(next, len, m, n, jumps, visited);
            }
        }

        visited[num] = false;
        return ret;
    }
};
