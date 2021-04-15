#include <algorithm>
#include <vector>

std::vector< std::vector<int> > subsets(std::vector<int>& nums) //Elements are not unique
{
    std::sort(nums.begin(), nums.end());
    std::vector< std::vector<int> > ans;
    ans.push_back( std::vector<int>() );

    int size = nums.size();
    for (int i = 0; i < size;)
    {
        int count {0};
        while (i + count < size && nums[i] == nums[i + count])
        {
            count++;
        }

        int prevSize = ans.size();
        for (int j = 0; j < prevSize; j++)
        {
            std::vector<int> tmp = ans[j];
            for (int k = 0; k < count; k++)
            {
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        i += count;
    }
    return ans;
}