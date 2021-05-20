#include <unordered_map>
#include <vector>

int majorityElement(std::vector<int> nums)
{
    std::unordered_map<int, int> map;
    for (auto& x : nums)
    {
        map[x]++;
    }

    int key {0};
    int val {0};
    for (auto& x : map)
    {
        if ( x.second > val )
        {
            val = x.second;
            key = x.first;
        }
    }
    return key;
}