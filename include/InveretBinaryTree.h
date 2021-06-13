#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) //BFS could be also used with std::queue, but it uses more memory in this case for queue.
{
	if (!root)
	{
		return root;
	}
	std::swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}