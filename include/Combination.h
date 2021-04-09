#include <vector>

using namespace std;

class A
{
private:
    vector<vector<int> > ans;
public:

    void help(int idx, vector<int>& tmp, const int& n, const int& k)        //Backtracking
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = idx; i <= n; i++)
        {
            tmp.push_back(i);
            help(i+1, tmp, n, k);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> res;
        help(1, res, n, k);
        return ans;
    }
};

vector<vector<int> > combine(int n , int k)     //No backtracking
{
    vector<vector<int> > ans;
    vector<int> tmp(k, 0);
    int maxIdx = k - 1; //In terms of index, not size.
    int curr = 0;

    while (curr >= 0)
    {
        if (++tmp[curr] > n)
        {
            curr--;
        }
        else if (curr == maxIdx)
        {
            ans.push_back(tmp);
        }
        else
        {
            tmp[curr+1] = tmp[curr];
            curr++;
        }
    }

    return ans;
}