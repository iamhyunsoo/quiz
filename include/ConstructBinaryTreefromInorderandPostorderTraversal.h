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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            mMap[inorder[i]] = i;
        }

        return help(inorder, 0, size - 1, postorder, 0, size - 1);
    }
private:
    TreeNode* help(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright)
    {
        if (ileft > iright)
        {
            return nullptr;
        }
        
        int rootVal = postorder[pright];
        TreeNode* root = new TreeNode(rootVal);
        if (ileft == iright)        //Doesn't need to do recursize with nullptr childs, so it just returns it right away.
        {
            return root;
        }

        int rootIdx = mMap[rootVal];
        int leftCnt = rootIdx - ileft;
        root->right = help(inorder, rootIdx + 1, iright, postorder, pleft + leftCnt, pright - 1);
        root->left  = help(inorder, ileft, rootIdx - 1, postorder, pleft, pleft + leftCnt - 1);

        return root;
    }
private:
    std::unordered_map<int, int> mMap;
};