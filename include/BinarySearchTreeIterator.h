#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode* root)
    {
        PushLeft(root);
    }
    int next()
    {
        auto tmp = mStack.top();
        mStack.pop();

        if (tmp->right)
        {
            PushLeft(tmp->right);
        }
        return tmp->val;
    }
    bool hasNext()
    {
        return !mStack.empty();
    }

private:
    void PushLeft(TreeNode* root)
    {
        TreeNode* tmp = root;
        while (tmp)
        {
            mStack.push(tmp);
            tmp = tmp->left;
        }
    }

private:
    std::stack<TreeNode*> mStack;
};