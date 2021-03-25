#include <vector>

using namespace std;
class Sol
{
public:
    void solve(vector<int>& nums, vector<int>& tmp, const int& size)
    {
        if (tmp.size() == size)
        {
            ans.push_back(tmp);
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (visited[i])
                {
                    continue;
                }
                visited[i] = true;
                tmp.push_back(nums[i]);

                solve(nums, tmp, size);

                visited[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        int size = nums.size();
        for (int i = 0 ; i < size; i++)
            visited.push_back(false);
        vector<int> tmp;

        solve(nums, tmp, size);

        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<bool> visited;   
};

class Sol2
{
public:

    void solve(vector<int>& nums, int l, int r)
    {
        if (l == r)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = l; i <= r; i++)
        {
            std::swap(nums[l], nums[i]);
            solve(nums, l + 1, r);
            std::swap(nums[l], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        solve(nums, 0, nums.size() - 1);
        return ans;
    }

private:
    vector<vector<int>> ans;
};

#include <algorithm>
class Solution  // STL version
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        do
        {
            ans.push_back(nums);
        }while(std::next_permutation(nums.begin(), nums.end()));
        
        return ans;
    }
};