#include <vector>

//[0,0,0,1,1,1,2,2,3,4,5,6,6,6] --> [0,1,2,3,4,5,6]
int RemoveDuplicates(std::vector<int>& nums)
{
    int size = nums.size();
    if (size <= 1)
        return size;

    int i {0};
    int j {1};
    while (j < size)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}