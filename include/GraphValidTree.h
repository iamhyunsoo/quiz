class UnionObject
{
public:
    UnionObject(int n)
    {
        for (size_t i = 0; i < n; i++)
        {
            mParent.push_back(i);
        }
    }

    bool UnionProcess(int a, int b)
    {
        int rootA = GetParent(a);
        int rootB = GetParent(b);

        if (rootA == rootB)
        {
            return false;
        }
        else
        {
            mParent[rootB] = rootA;
        }
        return true;
    }

    int GetParent(int no)
    {
        while (no != mParent[no])
        {
            no = mParent[no];
        }
        return no;
    }
    
private:
    std::vector<int> mParent;
};

class Solution 
{
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) 
    {
        if (n != edges.size() + 1)
        {
            return false;   // Not fully connected OR there might be cycles.
        }
        
        UnionObject obj(n);
        for (std::vector<int> const& edge : edges)
        {
            if (!obj.UnionProcess(edge[0], edge[1]))
            {
                return false;
            }
        }
        return true;
    }
};
