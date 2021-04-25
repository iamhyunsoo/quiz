#include <algorithm>
#include <cmath>

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
    bool isBalanced(TreeNode *root) 
    {
        return help(root) != -1;
    }
private:
    int help(TreeNode*& root)
    {
        if (!root)
            return 0;
        int left = help(root->left);
        if (left == -1)
            return -1;
        int right = help(root->right);
        if (right == -1)
            return -1;
        
        if (std::abs(left - right) > 1)
            return -1;
        
        return std::max(left, right) + 1;
    }
};