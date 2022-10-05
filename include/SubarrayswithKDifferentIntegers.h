class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
private:
    int helper(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> m;
        int numOfSubsets = 0;
        int r = 0;
        int l = 0;
        for (; r < nums.size(); ++r)
        {
            if (!m[nums[r]]++) { --k; }
            while (k < 0)
            {
                m[nums[l]]--;
                if (m[nums[l]] == 0) { ++k; }
                ++l;
            }
            numOfSubsets += r - l + 1;
        }
        return numOfSubsets;
    }
};
