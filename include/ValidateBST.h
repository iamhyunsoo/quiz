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
    bool isValidBST(TreeNode* root)
    {
        return help(root, nullptr, nullptr);
    }

private:
    bool help(TreeNode* node, TreeNode* min, TreeNode* max)
    {
        if (!node)
        {
            return true;
        }
        if ((max && node->val >= max->val) || (min && node->val <= min->val))
        {
            return false;
        }
        return help(node->left, min, node) && help(node->right, node, max);
    }
};