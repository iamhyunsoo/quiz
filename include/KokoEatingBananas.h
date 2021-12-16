class Solution 
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int maxBanana = *std::max_element(piles.begin(), piles.end());
        while (low < maxBanana)
        {
            int mid = low + (maxBanana - low) / 2;
            if (helper(piles, h, mid))
            {
                maxBanana = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool helper(vector<int>& piles, int h, int amt)
    {
        int totalTime {0};
        for (auto const& pile : piles)
        {
            totalTime += (pile - 1) / amt + 1;
        }
        return totalTime <= h;
    }
};
