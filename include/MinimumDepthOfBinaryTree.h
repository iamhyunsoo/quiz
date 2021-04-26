#include <algorithm>
#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) //Recursive
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;
    
    if (!root->left)
        return minDepth(root->right) + 1;

    if (!root->right)
        return minDepth(root->left) + 1;
    
    return std::min( minDepth(root->left), minDepth(root->right) ) + 1; 
}

int minDepth2(TreeNode* root) //BFS
{
    if (!root)
        return 0;
    
    std::queue<TreeNode*> q;
    int min = 1;

    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto tmp = q.front();
            q.pop();

            if (!tmp->left && !tmp->right)
                return min;
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        min++;
    }
    return min;
}