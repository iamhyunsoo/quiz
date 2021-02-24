#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i = 0;
        int j = 0;
        for (; i < static_cast<int>(nums.size()); ++i)
        {
            for (j = i + 1; j < static_cast<int>(nums.size()); ++j)
            {
                if ((nums[i] + nums[j]) == target)
                {
                     vector<int> ans {i, j};
                     return ans;
                }
            }
        }
        return {};
    }
};

#include <unordered_map>
class TwoSum
{
public:
    template<typename T>
    static std::vector<size_t> proc(const std::vector<T>& nums, T target)
    {
        std::unordered_map<T, size_t> map;
        size_t i = 0;
        for (; i < nums.size(); ++i)
        {
            T c = target - nums[i];
            if (map.count(c))
            {
                return {map[c], i};
            }
            map[nums[i]] = i;
        }       
        return {};
    }
};