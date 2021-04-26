#include <vector>

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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int sum)
    {
        std::vector<int> tmp;
        help (root, sum, tmp);

        return ans;
    }

private:
    void help(TreeNode* root, int sum, std::vector<int>& tmp)
    {
        if (!root)
            return;

        const int val = root->val;
        tmp.push_back(val);

        if (!root->left && !root->right && val == sum)
        {
            ans.push_back(tmp);
        }

        help(root->left, sum - val, tmp);
        help(root->right, sum - val, tmp);
        tmp.pop_back();
    }

private:
    std::vector<std::vector<int>> ans;
};