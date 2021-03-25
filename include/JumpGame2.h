#include <vector>

int jump(std::vector<int>& nums)
{
    size_t size = nums.size();
    if (size <= 1)
        return 0;
    
    int pastMax = nums[0];
    int nextMax = nums[0];
    int nextIdx {0};
    int i {0};
    int jump {0};
    
    while ((size_t)i < size)
    {
        jump++;
        while (i <= pastMax)
        {
            if (i + nums[i] >= pastMax)     //Greedy
            {
                nextMax = i + nums[i];
                nextIdx = i;
            }
            i++;
            if ((size_t)i == size)
            {
                return jump;
            }
        }
        i = nextIdx;
        pastMax = nextMax;
    }
    return jump;
}