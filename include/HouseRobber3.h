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
class Solution
{
public:
    int rob(TreeNode *root)
    {
        int l {0};
        int r {0};
        return robRecursive(root, l, r);
    }
private:
    int robRecursive(TreeNode* root, int& l, int& r)
    {
        if (!root)
        {
            return 0;
        }

        int ll {0};
        int lr {0};
        int rl {0};
        int rr {0};

        l = robRecursive(root->left, ll, lr);
        r = robRecursive(root->right, rl, rr);

        return std::max(root->val + ll + lr + rl + rr, l + r);
    }    
};