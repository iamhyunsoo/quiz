#include <vector>

using namespace std;

class Solution1
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) 
        {
            for (int ptr = layer; ptr < n - layer; ptr++) 
            {
                result[layer][ptr] = cnt++;
            }
            for (int ptr = layer + 1; ptr < n - layer; ptr++) 
            {
                result[ptr][n - layer - 1] = cnt++;
            }
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) 
            {
                result[n - layer - 1][ptr] = cnt++;
            }
            for (int ptr = n - layer - 2; ptr > layer; ptr--) 
            {
                result[ptr][layer] = cnt++;
            }
        }
        return result;
    }
};

class Solution2
{
public:

    long floorMod(long x, long y)           
    {
        return x - floorDiv(x, y) * y;
    }

    long floorDiv(long x, long y) 
    {
        long r = x / y;
        if ((x ^ y) < 0 && (r * y != x)) 
        {
            r--;
        }
        return r;
    }

    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n, vector<int>(n));
        int rule[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int row {0};
        int col {0};
        int cnt {1};
        int side {0};
        int r {0};
        int c {0};

        while (cnt <= n * n)
        {
            ans[row][col] = cnt++;
            r = floorMod(row + rule[side][0], n);            
            c = floorMod(col + rule[side][1], n);            
            if (ans[r][c] != 0)
            {
                side = (side + 1) % 4;
            }
            row += rule[side][0];
            col += rule[side][1];
        }        
        return ans;
    }
};