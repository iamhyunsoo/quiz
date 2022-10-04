class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for (auto const& n : nums)
        {
            s.insert(n);
            maxNum = std::max(maxNum, n);
            minNum = std::min(minNum, n);
        }
        return (maxNum - minNum + 1) == s.size() ? s.size() == nums.size() : false;
    }
};
