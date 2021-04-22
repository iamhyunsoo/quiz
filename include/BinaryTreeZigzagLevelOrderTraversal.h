#include <algorithm>
#include <stack>
#include <vector>

using std::vector;
using std::stack;

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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
        {
            return vector< vector<int> >{};
        }
        vector< vector<int> > ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        stack<TreeNode*>* p1 = &s1;
        stack<TreeNode*>* p2 = &s2;

        s1.push(root);
        while (!p1->empty())
        {
            ans.push_back( vector<int>(0) );

            while (!p1->empty())
            {
                TreeNode* cur = p1->top();
                p1->pop();
                ans.back().push_back(cur->val);

                if (p1 != &s2 && cur->left)
                {
                    p2->push(cur->left);
                }
                if (cur->right)
                {
                    p2->push(cur->right);
                }
                if (p1 == &s2 && cur->left)
                {
                    p2->push(cur->left);
                }
            }
            std::swap(p1, p2);
        }
        return ans;
    }
};
