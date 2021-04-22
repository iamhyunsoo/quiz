#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class S
{
public:
    int maxDepth(TreeNode* root) 
    {
        return root ? std::max(help(root->left), help(root->right)) + 1 : 0;    
    }
private:
    int help(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int lMax = help(root->left);
        int rMax = help(root->right);

        return std::max(lMax, rMax) + 1;
    }
};