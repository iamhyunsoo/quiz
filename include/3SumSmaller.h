class Solution 
{
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        if (nums.size() < 3) return 0;
        
        std::sort(nums.begin(), nums.end());
        
        int ret {0};
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            ret += GetSum(nums, target - nums[i], i + 1);
        }
        return ret;
    }
    
    int GetSum(vector<int>& nums, int target, int idx)
    {
        int left = idx;
        int right = nums.size() - 1;
        int ret {0};
        
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                ret += (right - left);
                left++;
            }
            else
            {
                right--;
            }
        }
        return ret;
    }
};

