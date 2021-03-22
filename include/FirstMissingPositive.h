//[-1,1,3,4]
#include <algorithm>
#include <vector>
#include <iostream>
int FirstMissingPositive(std::vector<int> nums)
{
    if (nums.empty())
    {
        return 1;
    }    

    std::sort(nums.begin(), nums.end());

    auto it = std::find(nums.begin(), nums.end(), 1);

    if (it != nums.end())
    {
        for (size_t i = 0 ; i < nums.size() - 1; i++)
        {
            int temp {0};
            if (nums[i] + 1 != nums[i + 1] && nums[i] != nums[i + 1])
            {
                temp =  nums[i] + 1;   
            }
            if (temp > 0)
            {
                return temp;
            }
        }
    }
    else
    {
        return 1;
    }

    return nums[nums.size()-1]+1;
}