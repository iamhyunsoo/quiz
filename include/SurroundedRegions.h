#include <vector>
using std::vector;

class S
{
public:
    void solve(vector<vector<char>>& board) 
    {
        int row = board.size();
        int col = board[0].size();
        if (row <= 1 || col <= 1)
        {
            return;
        }
        int i {0};
        int j {1};
        for (; i < row; i++)
        {
            if (board[i][0] == 'O')
            {
                help(board, i, 1);
            }
            if (board[i][col - 1] == 'O')
            {
                help(board, i, col - 2);
            }
        }
        for (; j < col - 1; j++)
        {
            if (board[0][j] == 'O')
            {
                help(board, 1, j);
            }
            if (board[row - 1][j] == 'O')
            {
                help(board, row - 2, j);   
            }
        }
        for (i = 1; i < row - 1; i++)
        {
            for (j = 1; j < col - 1; j++)
            {
                char &letter = board[i][j];
                if (letter == '#')
                {
                    letter = 'O';
                }
                else if (letter == 'O')
                {
                    letter = 'X';
                }
            }
        }
    }
private:
    void help(vector<vector<char>>& board, int r, int c)
    {
        char& letter = board[r][c];
        if (r <= 0 || c <= 0 || r >= board.size() -1 || c >= board[0].size() -1 || letter == 'X')
        {
            return;
        }
        if (letter == '#')
        {
            return;
        } 
        else if (letter == 'O')
        {
            letter = '#';
        }
        help(board, r + 1, c);
        help(board, r - 1, c);
        help(board, r, c + 1);
        help(board, r, c - 1);
    }
};