#include <algorithm>
#include <vector>
using std::vector;

int AdjustHeights(vector<vector<int>>& r)
{
    int maxHeight{ 0 };
    for (int i = 0; i < r.size() - 1; ++i)
    {
        int height1 = r[i][1];
        int height2 = r[i + 1][1];
        int possibleMaxHeight = height1 + (abs(r[i][0] - r[i + 1][0]));
        if (possibleMaxHeight > height2)
        {
            possibleMaxHeight = height2 + (possibleMaxHeight - height2) / 2;
        }
        r[i + 1][1] = std::min(height2, possibleMaxHeight);
        maxHeight = std::max(maxHeight, possibleMaxHeight);
    }
    return maxHeight;
}

int maxBuilding(int n, vector<vector<int>>& r)
{
    r.insert(r.end(), { {1, 0}, {n, n - 1} });
    std::sort(r.begin(), r.end());
    AdjustHeights(r);
    std::reverse(r.begin(), r.end());
    return AdjustHeights(r);
}
