class Solution{
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        mParents.assign(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            mParents[i] = i;
        }

        for (auto const& edge : edges)
        {
            n -= DoUnion(edge[0], edge[1]);
        }
        return n;
    }

    int DoUnion(int a, int b)
    {
        int rootA = GetParent(a);
        int rootB = GetParent(b);

        if (rootA == rootB)
        {
            return 0;
        }

        mParents[rootB] = rootA;
        return 1;
    }

    int GetParent(int num)
    {
        while (num != mParents[num])
        {
            num = mParents[num];
        }
        return num;
    }

private:
    std::vector<int> mParents;
};
