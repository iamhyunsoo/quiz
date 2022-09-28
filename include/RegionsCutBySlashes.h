class Solution {
private:
    void merge(std::vector<int>& parents, int a, int b)
    {
        parents[getParent(parents, b)] = getParent(parents, a);
    }
    int getParent(std::vector<int>& parents, int x)
    {
        return parents[x] == x ? x : getParent(parents, parents[x]);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        size_t n = grid.size();
        std::vector<int> parents(n * n * 4);
        std::iota(parents.begin(), parents.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int north = 4 * (n * i + j);
                char c = grid[i][j];
                if (c != '\\')
                {
                    merge(parents, north, north + 3);         
                    merge(parents, north + 1, north + 2);         
                }
                if (c != '/')
                {
                    merge(parents, north, north + 1);         
                    merge(parents, north + 2, north + 3);         
                }
     
                if (j < n -1)
                {
                    merge(parents, north + 1, north + 7);
                }
                if (j - 1 >= 0)
                {
                    merge(parents, north + 3, north - 3 );
                }
                if (i < n -1)
                {
                    int southRoot = 4 * (n * (i+1) + j);
                    merge(parents, north + 2, southRoot);
                }
                if (i - 1 >= 0)
                {
                    int northRoot = 4 * (n * (i - 1) + j);
                    merge(parents, north, northRoot + 2);
                }
            }
        }
        int answer = 0;
        for (size_t i = 0; i < n * n * 4; ++i)
        {
            if (getParent(parents, i) == i)
            {
                ++answer;
            }
        }
        return answer;
    }
};
