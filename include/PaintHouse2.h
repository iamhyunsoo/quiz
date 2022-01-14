class Solution
{
public:
    int minCostII(std::vector<std::vector<int>>& costs) 
    {
        int n = costs.size();
        int k = n ? costs[0].size() : 0;

        for (int row = 1; row < n; row++)
        {
            int firstSmallest {-1};
            int secondSmallest{-1};
            for (int color = 0; color < k; color++)
            {
                if (firstSmallest == -1 || costs[row-1][firstSmallest] > costs[row-1][color])
                {
                    secondSmallest = firstSmallest;
                    firstSmallest = color;
                }
                else if (secondSmallest == -1 || costs[row-1][secondSmallest] > costs[row-1][color])
                {
                    secondSmallest = color;
                }
            }

            for (int color = 0; color < k; color++)
            {
                if (color == firstSmallest)
                {
                    costs[row][color] += costs[row-1][secondSmallest];
                }
                else
                {
                    costs[row][color] += costs[row-1][firstSmallest];
                }
            }
        }       
        return *std::min_element(costs.back().begin(), costs.back().end());
    }
};
