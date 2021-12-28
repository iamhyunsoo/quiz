std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c) 
{
    std::vector<int> ret(nums.size(), 0);
    for (size_t i = 0; i < nums.size(); i++)
    {
        nums[i] = (nums[i]*nums[i]*a) + (nums[i]*b) + c;
    }

    int idx = a >= 0 ? nums.size() - 1 : 0;
    int start = 0;
    int end = nums.size() - 1;
    if (a >= 0)
    {
        while (idx >= 0)
        {
            ret[idx--] = nums[start] > nums[end] ? nums[start++] : nums[end--];
        }
    }
    else
    {
        while (idx < nums.size())
        {
            ret[idx++] = nums[start] < nums[end] ? nums[start++] : nums[end--];
        }
    }
    return ret;
}
