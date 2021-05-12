#include <algorithm>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using std::vector;
int maxPoints(vector<vector<int>>& points) 
{
    int ans {0};
    const int size = points.size();
    std::map< std::pair<int, int>, int > map;

    for (int i = 0; i < size - 1; i++)
    {
        map.clear();
        int duplicate {0};
        for (int j = i + 1; j < size; j++)
        {
            if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
            {
                duplicate++;
            }
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int gcd = std::__gcd(dx, dy);

            map[{dx / gcd, dy / gcd}]++;
        }
        for (auto& x : map)
        {
            ans = std::max(ans, x.second + duplicate);
        }
    }   
    return ans;
}