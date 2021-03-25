#include <vector>
#include <iostream>
using namespace std; //

class Solution 
{
public:
    static bool isValidSudoku(vector<vector<char> >& board) {
        int rows[9][10];
        int cols[9][10];
        int boxes[9][10];

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (++rows[i][num] > 1 || ++cols[j][num] > 1 || ++boxes[(i / 3) * 3 + j / 3][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
