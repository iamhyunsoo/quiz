#include <algorithm>
#include <bits/stdc++.h>

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
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        help(root, ans);
        return ans;
    }
private:
    int help(TreeNode* root, int& ans)
    {
        if (!root)
        {
            return 0;
        }

        int l = help(root->left, ans);
        int r = help(root->right, ans);

        int tmp = std::max( std::max(l, r) + root->val, root->val);
        int curMax = std::max( tmp, l + r + root->val);
        ans = std::max(ans, curMax);

        return tmp;
    }
};