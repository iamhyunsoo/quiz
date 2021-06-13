#include <stack>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) 	// Iterative One
{
	std::stack<TreeNode*> st;
	auto curr = root;
	while (curr || !st.empty())
	{
		while (curr)
		{
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top()->right;
		k--;
		if (k == 0)
		{
			return st.top()->val;
		}
		st.pop();
	}
	return 0;
}