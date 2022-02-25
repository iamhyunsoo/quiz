int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int ans {0};
    int unFlipped {0};
    int flipped {0};

    for (int const& num : nums)
    {
        if (num == 1)
        {
            unFlipped++;
            flipped++;
        }
        else
        {
            ans = std::max(ans, flipped);
            flipped = unFlipped + 1;
            unFlipped = 0;
        }
    }
    ans = std::max(flipped, ans);
    return ans;
}
