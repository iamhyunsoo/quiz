#include <string>
#include <vector>
using namespace std;

class Solution2
{
private:
    vector<int> queens;
    int count;
    
public:
    int totalNQueens(int n)  
    {
        queens.resize(n,0);
        solve(0, n);
        return this->count;
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
            this->count++;
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