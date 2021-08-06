#include <queue>
#include <vector>

std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
    std::vector<std::vector<int>> ret;
    auto cmp = [&nums1, &nums2](std::vector<int> const& a, std::vector<int> const& b) {
        return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> q(cmp);
    q.push({ 0,0 });

    while (k-- > 0 && q.size())
    {
        auto top = q.top();
        q.pop();

        ret.push_back({ nums1[top[0]], nums2[top[1]] });

        if (top[0] < nums1.size() - 1)
        {
            q.push({ top[0] + 1, top[1] });
        }
        if (top[0] == 0 && top[1] < nums2.size() - 1)
        {
            q.push({ top[0], top[1] + 1 });
        }
    }
    return ret;
}
