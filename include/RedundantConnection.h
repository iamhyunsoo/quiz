class Solution
{
private:
    std::vector<int> mParents;
    std::vector<int> mRanks;
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        std::vector<int> answers;
        mParents.assign(1001, 0);
        std::iota(mParents.begin(), mParents.end(), 0);
        mRanks.assign(1001, 0);
        for (auto& edge : edges)
        {
            if (!merge(edge))
            {
                return edge;
            }
        }
        return answers;
    }
private:
    int getParent(int x)
    {
        return mParents[x] == x ? x : getParent(mParents[x]);
    }
    bool merge(std::vector<int>& edge)
    {
        int l = getParent(edge[0]);
        int r = getParent(edge[1]);
        if (l == r)
        {
            return false;
        }
        if (mRanks[l] > mRanks[r])
        {
            mParents[r] = l;
        }
        else if (mRanks[l] < mRanks[r])
        {
            mParents[l] = r;
        }
        else
        {
            mParents[r] = l;
            ++mRanks[l];
        }
        return true;
    }
};
