#include <map>
#include <vector>

bool containsDuplicate(std::vector<int>& nums)
{
    std::map<int, int> m;
    for (auto& num : nums)
    {
        if (m[num])
        {
            return true;
        }
        m[num]++;
    }
    return false;
}

#include <set>
bool containsDuplicate2(std::vector<int>& nums)
{
    return nums.size() > std::set<int>(nums.begin(), nums.end()).size();
}
