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
    void recoverTree(TreeNode *root)
    {
        TreeNode* tmp = root;
        InOrder(tmp);

        if (first && second)
        {
            std::swap(first->val, second->val);
        }
    }

private:
    void InOrder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        InOrder(root->left);

        if (prev && root->val < prev->val)
        {
            if (!first)
            {
                first = prev;
            }
            second = root;
        }

        prev = root;
        InOrder(root->right);
    }
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
};