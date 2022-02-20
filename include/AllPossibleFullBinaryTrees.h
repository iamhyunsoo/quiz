
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <unordered_map>
#include <vector>

class Solution 
{
public:
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        if (mMemo.find(n) == mMemo.end())
        {
            if (n == 1)
            {
                mMemo[1].push_back(new TreeNode());
            }
            else if (n % 2 == 1)
            {
                std::vector<TreeNode*> tmp;
                for (int i = 0; i < n; i++)
                {
                    int j = n - i - 1;
                    for (auto const& left : allPossibleFBT(i))
                    {
                        for (auto const& right : allPossibleFBT(j))
                        {
                            TreeNode* node = new TreeNode();
                            node->left = left;
                            node->right = right;
                            tmp.push_back(node);
                        }
                    }
                }
                mMemo[n] = tmp;
            }
        }
        
        return mMemo[n];
    }
    
private:
    std::unordered_map<int, std::vector<TreeNode*>> mMemo;
};
