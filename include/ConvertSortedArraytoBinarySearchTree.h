#include <algorithm>
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

class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return help(nums, 0, nums.size() -1);
    }
private:
    TreeNode* help(vector<int>& nums, int s, int e)
    {
        if (s > e)
        {
            return nullptr;
        }
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (s == e)
        {
            return root;
        }
        root->left = help(nums, s, mid - 1);
        root->right= help(nums, mid + 1, e);
        return root;
    }
};