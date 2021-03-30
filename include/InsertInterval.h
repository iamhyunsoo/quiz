#include <algorithm>
#include <vector>

std::vector< std::vector<int> > insert(std::vector< std::vector<int> >& intervals, std::vector<int>& newInterval)
{
    int n = intervals.size();
    std::vector< std::vector<int> > ans;
    if (n == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }

    int i {0};
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i++]);
    }

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while ( i < n )
    {
        ans.push_back(intervals[i++]);
    }
    return ans;
}