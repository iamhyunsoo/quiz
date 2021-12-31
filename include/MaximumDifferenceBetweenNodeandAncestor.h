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
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        if (!root) return 0;
        return helper(root, root->val, root->val);
    }
    
    int helper(TreeNode* root, int curMax, int curMin)
    {
        if (!root)
        {
            return curMax - curMin;    
        }
        
        curMax = std::max(root->val, curMax);
        curMin = std::min(root->val, curMin);
        int left = helper(root->left, curMax, curMin);
        int right= helper(root->right, curMax, curMin);
        return std::max(left, right);
    }
};
