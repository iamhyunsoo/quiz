#include <algorithm>
#include <vector>

int rob(std::vector<int>& nums) 
{
    int prev {0};
    int curr {0};
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int tmp = std::max(prev + nums[i], curr);
        prev = curr;
        curr = tmp;
    }        
    return curr;
}