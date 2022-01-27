struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
public:
    std::vector<std::vector<int>> findLeaves(TreeNode* root) 
    {
        helper(root);
        return mRet;
    }
private:
    int helper(TreeNode*& root)
    {
        if (!root)
        {
            return -1;
        }
        
        int left = helper(root->left);
        int right= helper(root->right);
        int level = std::max(left, right) + 1;
        
        if (mRet.size() == level)
        {
            mRet.push_back({});
        }
        
        mRet[level].push_back(root->val);
        return level;
    }
private:
    std::vector<std::vector<int>> mRet;
};
