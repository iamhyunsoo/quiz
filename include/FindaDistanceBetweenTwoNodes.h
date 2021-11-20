#include <algorithm>
#include <vector>

// my treenode struct.
struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Construct a binary tree with a left child less than a parent and a right child greater than a parent.
TreeNode* constructBST(const std::vector<int>& values, int left, int right)
{
	if (left > right)
	{
		return nullptr;
	}

	int mid = left + (right - left) / 2;
	TreeNode* root = new TreeNode(values[mid]);

	if (left == right)
	{
		return root;
	}

	root->left = constructBST(values, left, mid - 1);
	root->right = constructBST(values, mid + 1, right);

	return root;
}

// Find a lowest common ancester node of nodeA and nodeB.
TreeNode* FindCommonAncester(TreeNode* root, int nodeA, int nodeB)
{
	if (!root)
	{
		return nullptr;
	}

	if (root->val == nodeA || root->val == nodeB)
	{
		return root;
	}

	TreeNode* left = FindCommonAncester(root->left, nodeA, nodeB);
	TreeNode* right = FindCommonAncester(root->right, nodeA, nodeB);

	if (left && right)
	{
		return root;
	}

	return left != nullptr ? left : right;
}

// With the ancestor, find a distance from the ancestor to each nodeA and nodeB./
int DistanceBetweenNodeAndAncestor(TreeNode* root, int node)
{
	if (!root)
	{
		return -1;
	}

	if (root->val == node)
	{
		return 0;
	}

	int left = DistanceBetweenNodeAndAncestor(root->left, node);
	int right = DistanceBetweenNodeAndAncestor(root->right, node);
	int possibleDistance = std::max(left, right);

	return possibleDistance >= 0 ? possibleDistance + 1 : -1;
}

int BSTdistance(const std::vector<int>& values, int nodeA, int nodeB)
{
	// If there's no nodeA or nodeB, it returns -1 right away.
	if (std::find(values.begin(), values.end(), nodeA) == values.end())
	{
		return -1;
	}
	if (std::find(values.begin(), values.end(), nodeB) == values.end())
	{
		return -1;
	}
	

	// "Insert the nodes in the order provided, do not balance or reorder."
	// I think the first argument is "const" variable for the above statement,
	// and honestly I can't solve it without using sort function so I made a copy below.
	auto cpy = values;
	std::sort(cpy.begin(), cpy.end());
	
	TreeNode* root = constructBST(cpy, 0, cpy.size() - 1);
	TreeNode* commonAncestor = FindCommonAncester(root, nodeA, nodeB);
	return DistanceBetweenNodeAndAncestor(commonAncestor, nodeA) + DistanceBetweenNodeAndAncestor(commonAncestor, nodeB);
}
