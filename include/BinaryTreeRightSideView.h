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

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> ret;
        help(root, ret, 0);
        return ret;
    }
private:
    void help(TreeNode* root, std::vector<int>& vec, const int level)
    {
        if (!root) return;

        if (vec.size() == level)
        {
            vec.push_back(root->val);
        }
        help(root->right, vec, level + 1);
        help(root->left, vec, level + 1);
        
        return;
    }
};