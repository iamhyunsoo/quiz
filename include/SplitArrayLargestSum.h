class Solution 
{
public:
    int splitArray(vector<int> nums, int m) 
    {
        
        int l = *std::max_element(nums.begin(), nums.end());
        int r = std::accumulate(nums.begin(), nums.end(), 0);

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (Possible(mid, nums, m - 1))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
private:
    bool Possible(const int& mid, std::vector<int> const& nums, int m)
    {
        int sum{ 0 };
        for (auto const& num : nums)
        {
            if (num > mid)
            {
                return false;
            }
            else if (sum + num <= mid)
            {
                sum += num;
            }
            else
            {
                m--;
                if (m < 0)
                {
                    return false;
                }
                sum = num;
            }
        }
        return true;
    }
};
