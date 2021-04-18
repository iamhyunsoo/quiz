#include <vector>

using std::vector;

 struct TreeNode {
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
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0)
        {
            return vector<TreeNode*>();
        }
        return help(1, n);
    }
private:
    vector<TreeNode*> help(int s, int e)    //start & end
    {
        vector<TreeNode*> vec;
        if (s > e)
        {
            vec.push_back(nullptr);
            return vec;
        }

        for (int i = s; i <= e; i++)
        {
            vector<TreeNode*> left = help(s, i-1);
            vector<TreeNode*> right= help(i+1, e);

            for (TreeNode* x : left)
            {
                for (TreeNode* y : right)
                {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = x;
                    tmp->right= y;
                    vec.push_back(tmp);
                }
            }
        }
        return vec;
    }
};