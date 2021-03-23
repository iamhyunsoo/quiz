#include <vector>


int trappingRainWater(const std::vector<int>& heights)
{
    int left {0};
    int right = heights.size() - 1;
    int lMax {0};
    int rMax {0};
    int ans  {0};

    while (left < right)
    {
        if (heights[left] < heights[right])
        {
            heights[left] >= lMax ? lMax = heights[left] : ans += lMax - heights[left];
            left++;
        }
        else
        {
            heights[right] >= rMax ? rMax = heights[right] : ans += rMax - heights[right]; 
            right--;
        }
    }

    return ans;
}