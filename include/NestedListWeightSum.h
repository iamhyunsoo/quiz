class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return getSum(nestedList, 1);
    }
private:
    int getSum(vector<NestedInteger>& nestedList, int level)
    {
        int sum {0};
        for (auto & nest : nestedList)
        {
            if (nest.isInteger())
            {
                sum += nest.getInteger() * level;
            }
            else
            {
                sum += getSum(nest.getList(), level + 1);
            }
        }
        return sum;
    }
};
