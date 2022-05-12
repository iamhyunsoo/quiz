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
    std::unordered_map<int, int> mMap;
public:
    bool checkEqualTree(TreeNode* root) 
    {
        int totalSum = this->GetSum(root);
        return totalSum == 0 ?\
                 mMap[totalSum] > 1 : \
                 totalSum % 2 == 0 && mMap.count(totalSum / 2);
    }
    
    int GetSum(TreeNode* root) 
    {
        if (!root) { return 0; }
        int sum = root->val + GetSum(root->left) + GetSum(root->right);
        mMap[sum]++;
        return sum;
    }
};
