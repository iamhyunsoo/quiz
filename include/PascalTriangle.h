#include <vector>

using std::vector;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;

    ans.push_back(vector<int>(0));
    ans.back().push_back(1);

    for (int i = 1; i < numRows; i++)
    {
        vector<int> v;
        auto prev = ans.back();

        v.push_back(1);
        for (int j = 1; j < i; j++)
        {
            v.push_back(prev[j - 1] + prev[j]);
        }
        v.push_back(1);
        
        ans.push_back(v);
    }
    return ans;
}