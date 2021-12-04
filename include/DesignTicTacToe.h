class TicTacToe2
{
public:
    TicTacToe2(int n) 
    {
        mSize = n;
        mDiagonal = 0;
        mAntiDiagonal = 0;
        mRows.assign(n, 0);
        mCols.assign(n, 0);
    }

    int move(int row, int col, int player) 
    {
        int currPlayer = (player == 1) ? 1 : -1;

        mRows[row] += currPlayer;
        mCols[col] += currPlayer;

        if (row == col)
        {
            mDiagonal += currPlayer;
        }
        
        if (row == mSize - col - 1)
        {
            mAntiDiagonal += currPlayer;
        }

        if (std::abs(mRows[row]) == mSize || std::abs(mCols[col]) == mSize || std::abs(mDiagonal) == mSize || std::abs(mAntiDiagonal) == mSize)
        {
            return player;
        }
        
        return 0;
    }

private:
    int mSize;
    int mDiagonal;
    int mAntiDiagonal;
    std::vector<int> mRows;
    std::vector<int> mCols;
};
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

class TicTacToe
{
public:
    vector<vector<int>> board;
    int n;

    TicTacToe(int n)
    {
        board.assign(n, vector<int>(n, 0));
        this->n = n;
    }

    int move(int row, int col, int player)
    {
        board[row][col] = player;

        if (checkCol(col, player) ||
            checkRow(row, player) ||
            (row == col && checkDiagonal(player)) ||
            (row == n - col - 1 && checkAntiDiagonal(player)))
        {
            return player;
        }

        return 0;
    }

    bool checkDiagonal(int player)
    {
        for (int row = 0; row < n; row++)
        {
            if (board[row][row] != player)
                return false;
        }
        return true;
    }

    bool checkAntiDiagonal(int player)
    {
        for (int row = 0; row < n; row++)
        {
            if (board[row][n - row - 1] != player)
                return false;
        }
        return true;
    }

    bool checkCol(int col, int player)
    {
        for (int row = 0; row < n; row++)
        {
            if (board[row][col] != player)
                return false;
        }
        return true;
    }

    bool checkRow(int row, int player)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] != player)
                return false;
        }
        return true;
    }
};
