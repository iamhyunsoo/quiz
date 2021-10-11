int minPatches(vector<int>& nums, int n) 
{
    int ret{ 0 };
    long sum{ 0 };
    int idx{ 0 };
    int size = nums.size();
    while (sum < n)
    {
        if (idx < size && nums[idx] <= sum + 1)
        {
            sum += nums[idx++];
        }
        else
        {
            ret++;
            sum += sum + 1;
        }
    }
    return ret;
}
