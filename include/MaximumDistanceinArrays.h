class Solution 
{
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int ret {0};
        int curMin = arrays[0][0];
        int curMax = arrays[0][arrays[0].size() - 1];
        
        for (size_t i = 1; i < arrays.size(); i++)
        {
            ret = std::max(ret, std::max(std::abs(arrays[i][0] - curMax), std::abs(arrays[i][arrays[i].size() - 1] - curMin)));
            curMin = std::min(curMin, arrays[i][0]);
            curMax = std::max(curMax, arrays[i][arrays[i].size() - 1]);
        }
        
        return ret;
    }
    
    int maxDistance2(vector<vector<int>>& arrays)   // inefficient
    {
        int ret {0};
        for (size_t i = 0; i < arrays.size() - 1; i++)
        {
            for (size_t j = i + 1; j < arrays.size(); j++)
            {
                ret = std::max(ret, std::abs(arrays[i][0] - arrays[j][arrays[j].size() - 1]));
                ret = std::max(ret, std::abs(arrays[j][0] - arrays[i][arrays[i].size() - 1]));
            }
        }
        return ret;
    }
};
