
struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Solution437 
{
public:
	int pathSum(TreeNode* root, int targetSum) 
	{
		if (!root) return 0;
		return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
	}

	int dfs(TreeNode* root, int targetSum)
	{
		if (!root) return 0;
		int remainingSum = targetSum - root->val;
		return (remainingSum == 0) + dfs(root->left, remainingSum) + dfs(root->right, remainingSum);
	}
};
