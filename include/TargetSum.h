class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        mTotal = std::accumulate(nums.begin(), nums.end(), 0);
        mTarget = target;
        mDP.assign(nums.size(), std::vector<int>(mTotal * 2 + 1, INT_MIN));
        return helper(nums, 0, 0);
    }
    
private:
    int helper(vector<int>& nums, int sum, int idx)
    {
        if (idx == nums.size())
        {
            if (sum == mTarget)
            {
                return 1;
            }
            return 0;
        }
        else
        {
            if (mDP[idx][mTotal + sum] != INT_MIN)
            {
                return mDP[idx][mTotal + sum];
            }
            int add = helper(nums, sum + nums[idx], idx + 1);
            int sub = helper(nums, sum - nums[idx], idx + 1);
            mDP[idx][mTotal + sum] = add + sub;
        }
        return mDP[idx][mTotal + sum];
    }
private:
    std::vector<std::vector<int>> mDP;
    int mTotal;
    int mTarget;
};

class Solution1 {
public:
    int cnt;
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, target, 0); 
        return cnt;   
    }
    
    void helper(vector<int>& nums, int target, int idx)
    {
        if (idx == nums.size())
        {
            if (target == 0)
            {
                cnt++;
            }
        }
        else
        {
            helper(nums, target - nums[idx], idx + 1);
            helper(nums, target + nums[idx], idx + 1);
        }
    }
};
