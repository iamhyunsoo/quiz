class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        std::unordered_map<int, int> mp;
        std::vector<std::vector<int>> nums = {nums1, nums2, nums3, nums4};
        AddFirstHalf(nums, mp, 0, 0);
        return AddLastHalf(nums, mp, nums.size() / 2, 0);
    }

    void AddFirstHalf(std::vector<std::vector<int>>& nums, std::unordered_map<int, int>& mp, int i, int sum)
    {
        if (i == nums.size() / 2)
        {
            mp[sum]++;
        }
        else
        {
            for (auto const& num : nums[i])
            {
                AddFirstHalf(nums, mp, i + 1, sum + num);
            }  
        }
    }

    int AddLastHalf(std::vector<std::vector<int>>& nums, std::unordered_map<int, int>& mp, int i, int sum)
    {
        if (i == nums.size())
        {
            auto cnt = mp.find(sum) != mp.end() ? mp[sum] : 0;
            return cnt;
        }
    
        int cnt {0};
        for (auto const& num : nums[i])
        {
            cnt += AddLastHalf(nums, mp, i + 1, sum - num);
        }
        return cnt;
    }
};
