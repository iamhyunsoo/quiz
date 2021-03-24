
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
    int n = startTime.size();
    int answer {0};
    int i{0};

    std::vector<std::pair<int,int>> v;
    std::vector<int> vals(n, 0);

    for (; i < n; i++)
    {
        v.push_back({startTime[i], i});
    }
    
    std::sort(v.begin(), v.end());

    for (i = n - 1; i >= 0; i--)
    {
        int idx = v[i].second;
        int value = 0;
        value += profit[idx];

        int end = endTime[idx];

        auto it = std::lower_bound(v.begin(), v.end(), end, [](const std::pair<int, int>& p, const int& x){
            return p.first < x;
        });

        if (it != v.end())
        {
            value += vals[it - v.begin()];
        }

        if (i == n - 1)
        {
            vals[i] = value;
        }
        else
        {
            vals[i] = std::max(value, vals[i+1]);
        }
        answer = std::max(answer, vals[i]);
    }
    
    return answer;
}