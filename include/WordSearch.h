#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution
{
public:
    bool help(const vector<vector<char>>& board, const string& word, int idx, int r, int c)
    {
        if (board[r][c] != word[idx])
        {
            return false;
        }

        if (word.size() - 1 == idx)     //Finish
        {
            return true;
        }

        this->table[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int tmpR = r + adj[i];
            int tmpC = c + adj[i+1];
            if (tmpR < 0 || tmpC < 0 || tmpR == this->row || tmpC == this->col || this->table[tmpR][tmpC])
            {
                continue;
            }

            if (help(board, word, idx + 1, tmpR, tmpC))
            {
                return true;
            }
        }
        this->table[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        this->row = board.size();
        this->col = board[0].size();
        this->table.assign(row, vector<bool>(col, false));

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (help(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int row;
    int col;
    const int adj[5] = {0, -1, 0, 1, 0};    //Adding these makes current indexes of the table able to move up & down & right & left
    vector< vector<bool> > table;
};