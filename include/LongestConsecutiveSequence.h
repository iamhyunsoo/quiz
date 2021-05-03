#include <algorithm>
#include <unordered_set>
#include <vector>

int longestConsecutive(std::vector<int> const& nums)
{
    std::unordered_set<int> list(nums.begin(), nums.end());
    int res {0};
    while (list.size() > res)
    {
        auto l = *list.begin();
        auto r = l + 1;
        while (list.erase(l))
        {
            l--;
        }
        while (list.erase(r))
        {
            r++;
        }
        res = std::max(res, r - l - 1);
    }
    return res;
}