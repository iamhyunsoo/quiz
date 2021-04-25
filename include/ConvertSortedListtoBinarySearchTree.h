struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        std::vector<int> vec;
        while (head)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        return help(vec, 0, vec.size() - 1);
    }
private:
    TreeNode* help(std::vector<int>& vec, int s, int e)
    {
        if (s > e)
        {
            return nullptr;
        }
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        if (s == e)
        {
            return root;
        }
        root->left = help(vec, s, mid - 1);
        root->right= help(vec, mid + 1, e);

        return root;
    }
};