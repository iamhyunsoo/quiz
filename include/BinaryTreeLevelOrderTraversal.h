#include <queue>
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

std::vector< std::vector<int> > levelOrder(TreeNode* root)
{
    if (!root)
        return {};
        
    std::queue<TreeNode*> que;
    std::vector< std::vector<int> > ans;

    std::vector<int> tmp;
    que.push(root);
    while(!que.empty())
    {
        tmp.clear();
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* front = que.front();
            que.pop();
            tmp.push_back(front->val);

            if (front->left) 
                que.push(front->left);
            
            if (front->right)
                que.push(front->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}