#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:

    bool rows[9][9] = { {false} };
    bool cols[9][9] = { {false} };
    bool boxes[9][9]= { {false} };

    bool IsValid(int row, int col, char c)
    {
        return rows[row][c - '0' - 1] || cols[col][c - '0' - 1] || boxes[(row / 3) * 3 + (col / 3)][c - '0' - 1];
    }

    void SetBoard(std::vector< std::vector< char > >& board, bool yesno, char c, int row, int col)
    {
        if (yesno)
        {
            board[row][col] = c;
        }
        else
        {
            board[row][col] = '.';
        }
        rows[row][c - '0' - 1] = yesno;
        cols[col][c - '0' - 1] = yesno;
        boxes[(row / 3) * 3 + (col / 3)][c - '0' - 1] = yesno;
    }

    bool solve(std::vector< std::vector< char > >& board, int idx)
    {
        if (idx == 81)
        {
            return true;
        }        

        int row = idx / 9;
        int col = idx % 9;
        
        if (board[row][col] != '.')
        {
            solve(board, ++idx);
        }

        for (char c = '1'; c <= '9'; c++)
        {
            if (!IsValid(row, col, c))
            {
                SetBoard(board, true, c, row, col);
                if (solve(board, ++idx))
                {
                    return true;
                }
                SetBoard(board, false, c, row, col);    //Backtracking
            }
        }
        return false;
    }

    void solveSudoku(std::vector< std::vector< char > >& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    rows[i][board[i][j] - '0' - 1] = true;
                    cols[j][board[i][j] - '0' - 1] = true;
                    boxes[(i / 3) * 3 + (j / 3)][board[i][j] - '0' - 1] = true;
                }
            }
        }

        solve(board, 0);
    }
};
