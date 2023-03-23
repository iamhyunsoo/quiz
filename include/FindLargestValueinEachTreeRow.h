/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        std::vector<int> res;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int mx = INT_MIN;
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto r = q.front();
                q.pop();
                mx = std::max(mx, r->val);
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};
