#include <algorithm>
#include <vector>

// [4,5,6,7,7,7,8,9] , target = 7 , answer = [3,5]
std::vector<int> searchRange(std::vector<int>& nums, int target) 
{
    std::vector<int> ans(2,-1);
    auto it1=std::lower_bound(nums.begin(),nums.end(),target);
    auto it2=std::upper_bound(nums.begin(),nums.end(),target);
    if(it1==nums.end()||nums[it1-nums.begin()]!=target) 
        return ans;
    ans[0]=it1-nums.begin();
    ans[1]=it2-nums.begin()-1;
    return ans;
}