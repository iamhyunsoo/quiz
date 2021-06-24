#include <string>
#include <sstream>
#include <vector>

class Node
{
public:
	int mVal;
	std::vector<Node *> mChildren;
	Node() {}
	Node(int _val, std::vector<Node *> children)
	{
		mVal = _val;
		mChildren = children;
	}
};

class Codec
{
public:
	// Encodes a tree to a single string.
	std::string serialize(Node *root)
	{
		std::string data;
		serializeHelper(root, data);
		return data;
	}

	// Decodes your encoded data to tree.
	Node *deserialize(std::string data)
	{
		std::istringstream is(data);
		return deserializeHelper(is);
	}

private:
	void serializeHelper(Node* root, std::string& data)
	{
		data += std::to_string(root->mVal) + " " + std::to_string(root->mChildren.size()) + " ";
		for (auto const& child : root->mChildren)
		{
			serializeHelper(child, data);
		}
	}
	
	Node* deserializeHelper(std::istringstream& is)
	{
		std::string val {""};
		std::string size {""};

		is >> val;
		is >> size;

		Node* root = new Node(std::stoi(val), {});
		for (int i = 0; i < std::stoi(size); i++)
		{
			root->mChildren.push_back(deserializeHelper(is));
		}

		return root;
	}
};


// TEST
/*
#include <iostream>
void Print(Node* root)
{
  std::cout << root->mVal << " ";
  for (auto const& child : root->mChildren)
  {
    Print(child);
  }
}

int main()
{

	Node* root = new Node(1, {});
	root->mChildren.push_back(new Node(2, {}));
	root->mChildren.push_back(new Node(3, {}));
	root->mChildren.push_back(new Node(4, {}));
	root->mChildren.push_back(new Node(5, {}));
	root->mChildren[1]->mChildren.push_back(new Node(6, {}));
	root->mChildren[1]->mChildren.push_back(new Node(7, {}));

	root->mChildren[1]->mChildren[1]->mChildren.push_back(new Node(11, {}));
	root->mChildren[1]->mChildren[1]->mChildren[0]->mChildren.push_back(new Node(14, {}));

	root->mChildren[2]->mChildren.push_back(new Node(8, {}));
	root->mChildren[2]->mChildren[0]->mChildren.push_back(new Node(12, {}));

	root->mChildren[3]->mChildren.push_back(new Node(9, {}));
	root->mChildren[3]->mChildren.push_back(new Node(10, {}));
	root->mChildren[3]->mChildren[0]->mChildren.push_back(new Node(13, {}));


	Print(root);
	std::cout << std::endl;

	Codec c;
	auto res = c.serialize(root);
	std::cout <<res << std::endl;

	auto tmp = c.deserialize(res);
	Print(tmp);
}
*/