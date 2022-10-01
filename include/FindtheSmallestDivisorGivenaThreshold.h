class Solution 
{
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int l = 1;
        int r = *std::max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int m = (l + r) / 2;
            int sumQuo = 0;
            for (auto const& x : nums)
            {
                sumQuo += ceil((double)x / m);
            }
            if (sumQuo > threshold)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
