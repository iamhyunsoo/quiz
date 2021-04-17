#include <vector>
using std::vector;

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
private:
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        help(root);
        return ans;
    }
    void help(TreeNode* root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
};