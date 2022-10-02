class Solution {
    std::vector<int> parent;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        auto n = edges.size();
        parent.resize(n + 1, 0);
        std::vector<int> firstOption;
        std::vector<int> secondOption;
        for (auto& edge : edges)
        {
            if (parent[edge[1]] == 0)
            {
                parent[edge[1]] = edge[0];
            }
            else
            {
                firstOption = { parent[edge[1]], edge[1] };
                secondOption = edge;
                edge[1] = 0;
            }
        }
        std::iota(parent.begin(), parent.end(), 0);
        for (auto& edge : edges)
        {
            if (edge[1] == 0)
            {
                continue;
            }
            auto rootU = getParent(edge[0]);
            if (rootU == edge[1])
            {
                return firstOption.empty() ? edge : firstOption;
            }
            parent[edge[1]] = edge[0];
        }
        return secondOption;
    }

private:
    int getParent(int n)
    {
        return parent[n] == n ? n : getParent(parent[n]);
    }
};
