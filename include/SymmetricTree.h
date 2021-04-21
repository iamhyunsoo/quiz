struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Sol
{
public:
    bool isSymmetric(TreeNode* root)
    {
        return help(root, root);
    }
private:
    bool help(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        
        if (!p || !q)
            return false;
        
        return (p->val == q->val) && help(p->left, q->right) && help(p->right, q->left);
    }
};