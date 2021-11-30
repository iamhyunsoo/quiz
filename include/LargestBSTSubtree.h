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
    bool IsValidTree(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }
        
        int maxLeft = GetMaxValue(root->left);
        if (maxLeft >= root->val)
        {
            return false;
        }
        
        int minValue = GetMinValue(root->right);
        if (minValue <= root->val)
        {
            return false;
        }
        
        if (IsValidTree(root->left) && IsValidTree(root->right))
        {
            return true;
        }
        
        return false;
    }
    
    int GetMaxValue(TreeNode* root)
    {
        if (!root)
        {
            return INT_MIN;
        }
        
        return std::max({root->val, GetMaxValue(root->left), GetMaxValue(root->right)});
    }
    
    int GetMinValue(TreeNode* root)
    {
        if (!root)
        {
            return INT_MAX;
        }
        
        return std::min({root->val, GetMinValue(root->left), GetMinValue(root->right)});
    }   
    
    int GetNodeCount(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        
        return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
    }   
    
    int largestBSTSubtree(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }
        
        if (IsValidTree(root))
        {
            return GetNodeCount(root);
        }
        
        return std::max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
