#include <unordered_map>
#include <vector>
using std::vector;

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
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        mCnt = 0;
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            mMap[inorder[i]] = i;
        }

        return help(preorder, 0, size - 1);
    }
private:
    TreeNode* help(vector<int>& preorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int rootVal = preorder[mCnt++];
        TreeNode* root = new TreeNode(rootVal);
        if (left == right)        //Doesn't need to do recursize with nullptr childs, so it just returns it right away.
        {
            return root;
        }

        root->left = help(preorder, left, mMap[rootVal] - 1);
        root->right= help(preorder, mMap[rootVal] + 1, right);

        return root;
    }
private:
    std::unordered_map<int, int> mMap;
    int mCnt;
};