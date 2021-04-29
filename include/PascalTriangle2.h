#include <vector>

using std::vector;

vector<int> getRow(int rowIndex)
{
    vector<int> prev(1,1);
    
    if (rowIndex == 0)
        return prev;

    vector<int> curr;
   
    for (int i = 1; i <= rowIndex; i++)
    {
        curr.clear();
        curr.push_back(1);
        for (int j = 1; j < i; j++)
        {
            curr.push_back(prev[j - 1] + prev[j]);
        }
        curr.push_back(1);

        prev = curr;
    }
    return curr;
}