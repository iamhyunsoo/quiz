#include <algorithm>
#include <vector>

std::vector< std::vector<int> > subsets(std::vector<int>& nums) //Elements are not unique
{
    std::sort(nums.begin(), nums.end());
    std::vector< std::vector<int> > ans;
    ans.push_back( std::vector<int>() );

    int size = nums.size();
    for (int i = 0; i < size;)
    {
        int count {0};
        while (i + count < size && nums[i] == nums[i + count])
        {
            count++;
        }

        int prevSize = ans.size();
        for (int j = 0; j < prevSize; j++)
        {
            std::vector<int> tmp = ans[j];
            for (int k = 0; k < count; k++)
            {
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        i += count;
    }
    return ans;
}

// Backtracking
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, curr, 0);
        return ans; 
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int idx)
    {
        ans.push_back(curr);
        for (int i = idx; i < nums.size(); ++i)
        {
            if (i != idx && nums[i-1] == nums[i]) { continue; }
            curr.push_back(nums[i]);
            helper(nums, ans, curr, i + 1);
            curr.pop_back();    
        }
    }
};
