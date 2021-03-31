#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> queens;
    vector<vector<string>> ans;
    
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        queens.resize(n,0);
        solve(0, n);
        return this->ans;
    }
    
    vector<string> MakeAnswer(const int& size)
    {
        vector<string>res(size,"");
        for(int i = 0;i<size;i++){
            res[i].resize(size,'.');
        }
        for(int i = 0;i<size;i++){
            res[i][queens[i]]='Q';
        }
        return res;
    }
    
    bool isValid(int row)
    {
        for (int i = 0; i < row; i++)
        {
            int diff = abs(queens[i] - queens[row]);
            if (diff == 0 || diff == row - i)
                return false;
        }
        return true;
    }
    
    void solve(int row, const int& size)
    {
        if (row == size)
        {
            ans.push_back(MakeAnswer(size)); 
            return;   
        }
        
        for (int i = 0; i < size; i++)
        {
            queens[row] = i;
            if (isValid(row))
            {
                solve(row + 1, size);
            }
        }
    }
};