class Solution {
    int longest_ = -1;
public:
    int longestCycle(vector<int>& edges) {
        size_t n = edges.size();
        std::vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                std::unordered_map<int, int> distance;
                distance[i] = 1;
                dfs(i, visited, distance, edges);
            }
        }
        return longest_;
    }
private:
    void dfs(int& cur, std::vector<bool>& visited, std::unordered_map<int, int>& distance, std::vector<int>& edges) {
        visited[cur] = true;
        if (edges[cur] != -1 && !visited[edges[cur]]) {
            distance[edges[cur]] = distance[cur] + 1;
            dfs(edges[cur], visited, distance, edges);
        } else if (edges[cur] != -1 && distance.count(edges[cur]) > 0) {
            longest_ = std::max(longest_, (distance[cur] - distance[edges[cur]] + 1));
        }
    }
};

/*
// Time Limit Exceeded O(n^2)
int longestCycle(vector<int>& edges) {
    int mxLen = -1;
    for (int i = 0; i < (int)edges.size(); ++i)
    {
        std::set<int> visited;
        int j = i;
        int cnt = 0;
        while(edges[j] != -1 && visited.count(j) < 1)
        {
            visited.insert(j);
            j = edges[j];
            cnt++;
        }
        if (j == i)
        {
            mxLen = std::max(mxLen, cnt);
        }   
    }
    return mxLen == 0 ? -1 : mxLen;
}
*/
