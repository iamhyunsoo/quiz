#include <set>
#include <map>
#include <vector>
using std::vector;

class Solution
{
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings)
    {
        std::multimap<int, int> coords;
        for (auto const& building : buildings)
        {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }        

        std::multiset<int> heights = { 0 };
        std::vector<std::vector<int>> corners;
        int x = -1;
        int y = 0;
        for (auto const& pos : coords)
        {
            if ((x >= 0) && (x != pos.first) && (corners.empty() || corners.rbegin()->at(1) != y))
            {
                corners.push_back({x, y});
            }

            if (pos.second > 0)
            {
                heights.insert(pos.second);
            }
            else
            {
                heights.erase(heights.find(-pos.second));                
            }
            x = pos.first;
            y = *heights.rbegin();
        }
        
        if (!corners.empty())
        {
            corners.push_back({x, 0});
        }

        return corners;
    }
};