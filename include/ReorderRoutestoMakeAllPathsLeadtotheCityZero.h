class Solution {
    int cnt_;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (auto const& c : connections)
        {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }
        dfs_helper(0, -1, adj);
        return cnt_;
    }
private:
    void dfs_helper(int cur, int parent, std::vector<std::vector<std::pair<int,int>>>& adj)
    {
        for (auto const& c : adj[cur])
        {
            if (c.first != parent)
            {
                cnt_ += c.second;
                dfs_helper(c.first, cur, adj);
            }
        }
    }
};
