#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] == 0))
            return ret;
        sort(nums.begin(), nums.end());
        
        int vecSize = nums.size();
        int l;
        int r;
        for (int i = 0; i < vecSize; i++)
        {
            
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            l = i + 1;
            r = vecSize  - 1;
            
            while (l < r)
            {
                if ((nums[i] + nums[l] + nums[r]) > 0)
                {
                    --r;
                }
                else if ((nums[i] + nums[l] + nums[r]) < 0)
                {
                    ++l;
                }
                else
                {
                    ret.emplace_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    ++l;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        ++l;
                    }
                }
            }
        }
        return ret;
    }
};
