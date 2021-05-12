#include "PascalTriangle.h"
#include "PascalTriangle2.h"
#include <iostream>
#include <cstring>
#include <string>
#include "MaxPointsonaLine.h"
using namespace std;
using std::vector;


class SS
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
        for (i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
            {
                help(board, 1, i);
            }
            if (board[row - 1][i] == 'O')
            {
                help(board, row - 2, i);
            }
        }
        for (i = 1; i < row-1; i++)
        {
            for (int j = 1; j < col-1; j++)
            {
                char& letter = board[i][j];
                if (letter == 'O')
                {
                    letter = 'X';
                }
                else if (letter == '#')
                {
                    letter = 'O';
                }
            }
        }
    }

private:
    void help(vector<vector<char>>& board, int r, int c)
    {
        char& letter = board[r][c];
        if (r <= 0 || c <= 0 || r >= board.size() - 1 || c >= board[0].size() - 1 || letter == 'X')
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

class AA
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        int len = s.length();
        vector<vector<bool>> dp (len, vector<bool>(len, false));
        help(0, s, curr, dp);
        return ans;
    }
private:
    void help(int start, string& s, vector<string>& curr, vector<vector<bool>>& dp)
    {
        if (start == s.length())
        {
            this->ans.push_back(curr);
            return;
        }
        
        for (int end = start; end < s.length(); end++)
        {
            if (s[start] == s[end] && ((end - start <= 2) || dp[start+1][end-1]))
            {
                dp[start][end] = true;
                curr.push_back(s.substr(start, end - start + 1));
                help(end + 1, s, curr, dp);
                curr.pop_back();
            }
        }
    }
private:
    vector<vector<string>> ans;
};
int main()
{
    std::vector<std::vector<int>> v = { {1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4} };
    maxPoints(v);

    SS sss;
    vector<vector<char>> vvv ={{ 'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}
                                };
    sss.solve(vvv);
    for (auto& x : vvv)
    {
        for (auto& u : x)
        {
            cout << u << " ";
        }
        cout << endl;
    }
}
