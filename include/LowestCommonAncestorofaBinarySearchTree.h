struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		auto node = root;
		auto pVal = p->val;
		auto qVal = q->val;
		while (node)
		{
			auto Val = node->val;
			if (Val < pVal && Val < qVal)
			{
				node = node->right;
			}
			else if (Val > pVal && Val > qVal)
			{
				node = node->left;
			}
			else
			{
				return node;
			}
		}
		return nullptr;
	}
};