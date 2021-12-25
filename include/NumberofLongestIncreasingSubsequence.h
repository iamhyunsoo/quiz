int findNumberOfLIS(std::vector<int> nums)
{
    size_t size = nums.size();
    std::vector<int> lens(size, 1);
    std::vector<int> cnts(size, 1);
    int maxLen{ 0 };
    int ret{ 0 };

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (lens[j] + 1 > lens[i])
                {
                    lens[i] = lens[j] + 1;
                    cnts[i] = cnts[j];
                }
                else if (lens[j] + 1 == lens[i])
                {
                    cnts[i] += cnts[j];
                }
            }
        }

        if (maxLen < lens[i])
        {
            maxLen = lens[i];
            ret = cnts[i];
        }
        else if (maxLen == lens[i])
        {
            ret += cnts[i];
        }
    }
    return ret;
}
