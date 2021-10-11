#include <cstdlib>
#include <unordered_map>
#include <vector>

class Solution 
{
public:
    Solution(std::vector<int>& nums) 
    {
        for (int i = 0 ; i < nums.size(); i++)
        {
            mDict[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        int size = mDict[target].size();
        return mDict[target][rand() % size];    
    }
private:
    std::unordered_map<int, std::vector<int>> mDict;
};