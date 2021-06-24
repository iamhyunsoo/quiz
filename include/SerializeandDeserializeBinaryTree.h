#include <string>
#include <sstream>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
	// Encodes a tree to a single string.
	std::string serialize(TreeNode *root)
	{
		return !root ? "NULL " : std::to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(std::string data)
	{
		std::istringstream is(data);
		return deserializeHelper(is);
	}

private:
	TreeNode* deserializeHelper(std::istringstream& is)
	{
		std::string tmp;
		is >> tmp;
		if (tmp == "NULL")
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(std::stoi(tmp));
		root->left = deserializeHelper(is);
		root->right= deserializeHelper(is);

		return root;
	}
};