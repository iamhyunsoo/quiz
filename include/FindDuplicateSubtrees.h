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
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        std::vector<TreeNode*> dup;
        std::unordered_map<std::string, size_t> mp;
        Helper(root, dup, mp);
        return dup;
    }
private:
    std::string Helper(TreeNode* root, std::vector<TreeNode*>& dup, std::unordered_map<std::string, size_t>& mp)
    {
        if (!root) return "";
        
        std::string str = std::to_string(root->val) + "-" + Helper(root->left, dup, mp) + "-" + Helper(root->right, dup, mp);
        mp[str]++;
        
        if (mp.at(str)==2)
        {
            dup.push_back(root);
        }
        
        return str;
    }
};
