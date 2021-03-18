#include <vector>


// [4,5,6,7,0,1,2] , target = 0 , answer = 4
int search(std::vector<int>& nums, int target)
{
    int len = nums.size();
    int l = 0;
    int r = len;
    int mid {0};

    while (l < r)
    {
        mid = ( l + r ) / 2;
        if (nums[mid] >= nums[0])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    
    if (l == len)
    {
        l = 0;
    }

    if (target >= nums[l] && target <= nums.back())
    {
        r = len;
    }
    else
    {
        r = l;
        l = 0;
    }

    while (l < r)
    {
        mid = ( l + r ) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }    
    return nums[l] == target ? l : -1;
}