class Solution 
{
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        mVisited.assign(n, false);
        MakeAdjacencyList(edges);
        
        int ret {0};
        mVisited[0] = true;
        for (auto const& node : mAdj[0])
        {
            ret += dfs(node, hasApple);
        }
        return ret;
    }
    
    int dfs(int node, vector<bool>& hasApple)
    {
        mVisited[node] = true;
        int ret {0};
        for (auto const& adj : mAdj[node])
        {
            if (mVisited[adj]) continue;
            
            ret += dfs(adj, hasApple);
        }
        
        if (hasApple[node] || ret)
        {
            ret += 2;
        }   
        
        return ret;
    }
    
    void MakeAdjacencyList(vector<vector<int>>& edges)
    {
        for (auto const& edge : edges)
        {
            mAdj[edge[0]].insert(edge[1]);
            mAdj[edge[1]].insert(edge[0]);
        }
    }
    
private:
    std::unordered_map<int, std::unordered_set<int>> mAdj;
    std::vector<bool> mVisited;
};
