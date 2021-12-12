class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        std::vector<int> colors(graph.size(), 0);        
        std::queue<int> que;
        
        for (size_t i = 0; i < graph.size(); i++)
        {
            if (colors[i]) continue;
            
            colors[i] = 1;
            que.push(i);
            while (!que.empty())
            {
                auto idx = que.front();
                que.pop();
                
                for (auto const& x : graph[idx])
                {
                    if (colors[x] == 0)
                    {
                        colors[x] = -1 * colors[idx];
                        que.push(x);
                    }
                    else if (colors[idx] == colors[x])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
