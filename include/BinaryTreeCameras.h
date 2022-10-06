/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    std::unordered_set<TreeNode*> mCovered;
    int mAns;
public:
    int minCameraCover(TreeNode* root) 
    {
        mAns = 0;
        mCovered.insert(nullptr);
        helper(root, nullptr);
        return mAns;
    }
private:
    void helper(TreeNode* root, TreeNode* parent)
    {
        if (!root) { return; }
        helper(root->left, root);
        helper(root->right, root);

        if ((mCovered.find(root) == mCovered.end() && !parent) 
        || !mCovered.count(root->left) || !mCovered.count(root->right))
        {
            ++mAns;
            mCovered.insert(root->left);
            mCovered.insert(root->right);
            mCovered.insert(root);
            mCovered.insert(parent);
        }
    }
};






