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
    int closestValue(TreeNode* root, double target) 
    {
        int closest = root->val;

        while (root)
        {
            int curVal = root->val;
            closest = abs(closest - target) > abs(curVal - target) ? curVal : closest;
            root = target > curVal ? root->right : root->left;
        }
        return closest;
    }
};
