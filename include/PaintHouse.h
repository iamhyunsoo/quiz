int minCost(vector<vector<int>>& costs) 
{
    int size = costs.size();
    for (size_t i = 1; i < size; i++)
    {
        costs[i][0] += std::min(costs[i-1][1], costs[i-1][2]);
        costs[i][1] += std::min(costs[i-1][0], costs[i-1][2]);
        costs[i][2] += std::min(costs[i-1][0], costs[i-1][1]);
    }

    return std::min(costs[size - 1][0], std::min(costs[size-1][1], costs[size-1][2]));
}
