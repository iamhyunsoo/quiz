class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t n = isConnected.size();
        mVisited.assign(n, false);
        
        int provinces {0};
        for (size_t i = 0; i < n; i++)
        {
            if (mVisited[i] == false)
            {
                provinces++;
                dfs(isConnected, i);
            }
        }
        return provinces;        
    }
    
    void dfs(vector<vector<int>>& isConnected, int idx)
    {
        for (size_t i = 0; i < isConnected.size(); i++)
        {
            if (idx != i && isConnected[idx][i] == 1 && mVisited[i] == false)
            {
                mVisited[i] = true;
                dfs(isConnected, i);
            }
        }      
    }
private:
    std::vector<bool> mVisited;
};
