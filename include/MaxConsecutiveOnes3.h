int longestOnes(vector<int>& nums, int k) 
{
    int i = 0;
    int j = 0;
    for (; j < nums.size(); ++j)
    {
        k -= nums[j] == 0;
        if (k < 0 && nums[i++] == 0)
        {
            ++k;
        }
    }
    return j - i;
}
