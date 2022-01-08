#include <algorithm>
#include <vector>

class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        const int n = 10001;
        std::vector<int> newNums(n, 0);
        for (auto const& num : nums)
        {
            newNums[num] += num;
        }
        
        int prev {0};
        int curr {0};
        for (int i = 0; i < n; i++)
        {
            int tmp = std::max(curr, prev + newNums[i]);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};
