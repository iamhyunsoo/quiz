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
class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {
        int totalMovement = 0;
        
        helperDFS(root, totalMovement);
        
        return totalMovement;
    }
    
    int helperDFS(TreeNode* root, int& totalMovement)
    {
        if (!root)
        {
            return 0;
        }
        
        int left = helperDFS(root->left, totalMovement);
        int right = helperDFS(root->right, totalMovement);
        
        totalMovement += (std::abs(left) + std::abs(right));
        
        return root->val - 1 + left + right;
    }
};
