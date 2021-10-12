
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution
{ 
public:
vector<vector<int>> levelOrder(Node* root) 
{
	if (root == nullptr) return {};
	vector<vector<int>> ret;
	std::queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		std::vector<int> level;
		for (int i = q.size(); i >= 1; i--)
		{
			Node* node = q.front();
			q.pop();
			level.push_back(node->val);
			for (Node* child : node->children)
			{
				q.push(child);
			}
		}
		ret.push_back(level);
	}
	return ret;
}
};
