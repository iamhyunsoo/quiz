struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root || root == p || root == q)
	{
		return root;
	}
	auto left = lowestCommonAncestor(root->left, p, q);
	auto right= lowestCommonAncestor(root->right, p, q);

	if (!left)
	{
		return right;
	}
	else if (!right)
	{
		return left;
	}
	return root;
}