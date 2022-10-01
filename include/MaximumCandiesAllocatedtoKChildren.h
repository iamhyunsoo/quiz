class Solution 
{
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int l = 0;
        int r = *std::max_element(candies.begin(), candies.end()) * 2;
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            long piles = 0;
            for (auto const& candi : candies)
            {
                piles += candi / m;
            }
            if (piles >= k)
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};
