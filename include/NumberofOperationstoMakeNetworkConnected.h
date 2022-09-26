// Two solutions

// Classic union find with ranks
class Solution 
{
public:
    int getParent(int n, std::vector<int>& parent)
    {
        return parent[n] = parent[n] == n ? n : getParent(parent[n], parent);
    }
    void merge(int u, int v, std::vector<int>& parent, std::vector<int>& rank)
    {
        int a = getParent(u, parent);
        int b = getParent(v, parent);
        if (rank[a] == rank[b])
        {
            ++rank[a];
        }
        
        if (rank[a] > rank[b])
        {
            parent[b] = a;
        }
        else
        {
            parent[a] = b;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) { return -1; }
        std::vector<int> parent(n);
        std::vector<int> rank(n);
        
        std::iota(parent.begin(), parent.end(), 0);
        
        for (auto const& con : connections)
        {
            merge(con[0], con[1], parent, rank);
        }
        
        int roots = 0;
        for (size_t i = 0; i < n; ++i)
        {
            if (parent[i] == i)
            {
                ++roots;
            }
        }
        return roots - 1;
    }
};

// dfs with union graph
class Solution 
{
private:
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
public:
    void checkAndVisitChildren(int nth)
    {
        this->visited[nth] = true;
        for (auto const child : this->adj[nth])
        {
            if (!this->visited[child])
            {
                this->checkAndVisitChildren(child);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) { return -1; }
        int roots = 0;
        
        this->adj.assign(n, std::vector<int>(0));
        this->visited.assign(n, false);
        
        for (auto const con: connections)
        {
            this->adj[con[0]].push_back(con[1]);
            this->adj[con[1]].push_back(con[0]);
        }
        for (size_t i = 0; i < n; ++i)
        {
            if (!this->visited[i])
            {
                this->checkAndVisitChildren(i);
                ++roots;        
            }
        }
        return roots - 1;
    }
};
