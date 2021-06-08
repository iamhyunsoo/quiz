#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        std::vector< std::vector< int > > ans;
        std::vector<int> curr;
        help(ans, curr, k, n);
        return ans;
    }
private:
    void help(std::vector< std::vector< int > >& ans, std::vector<int>& curr, int k, int n)
    {
        if (curr.size() == k && n == 0)
        {
            ans.push_back(curr);
            return;
        }

        if (curr.size() < k)
        {
            for (int i = curr.empty() ? 1 : curr.back() + 1; i < 10; i++)
            {
                if (n - i < 0)
                {
                    break;
                }
                curr.push_back(i);
                help(ans, curr, k, n - i);
                curr.pop_back();
            }
        }
    }
};