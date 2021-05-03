struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumNumbers(TreeNode* root)
{
    return help(root, 0);
}

int help(TreeNode* root, int sum)
{
    if (!root)
    {
        return 0;
    }
    sum = sum * 10 + root->val;
    if (!root->left && !root->right)
    {
        return sum;
    }
    return help(root->left, sum) + help(root->right, sum);
}