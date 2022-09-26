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
