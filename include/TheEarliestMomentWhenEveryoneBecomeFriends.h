class Solution 
{
public:
    int earliestAcq(std::vector<std::vector<int>>& logs, int n)
    {
        for (size_t i = 0; i < n; i++)
        {
            mRank.push_back(0);
            mFriendship.push_back(i);    
        }
        
        std::sort(logs.begin(), logs.end(), 
                  [](std::vector<int> const& a, std::vector<int> const& b)
                  {
                      return a[0] < b[0];
                  });        
        
        int numOfRelationship = n - 1; // If there are 3 people, the number of relationship is 2.
        for (std::vector<int> const& log : logs)
        {
            if (this->Union(log[1], log[2]))
            {
                numOfRelationship--;
            }
            
            if (!numOfRelationship)
            {
                return log[0];
            }
        }
        return -1;
    }
private:
    bool Union(int a, int b)
    {
        int aAncestor = this->Find(a);
        int bAncestor = this->Find(b);
        
        if (aAncestor == bAncestor)
        {
            return false;
        }
        
        if (mRank[aAncestor] > mRank[bAncestor])
        {
            mFriendship[bAncestor] = aAncestor;
        }
        else if (mRank[aAncestor] < mRank[bAncestor])
        {
            mFriendship[aAncestor] = bAncestor;
        }
        else
        {
            mFriendship[bAncestor] = aAncestor;
            mRank[aAncestor]++; 
        }
        return true;
    }
    
    int Find(int person)
    {
        if (mFriendship[person] != person)
        {
            mFriendship[person] = this->Find(mFriendship[person]);
        }
        return mFriendship[person];
    }
    
private:
    std::vector<int> mRank;
    std::vector<int> mFriendship;
};
