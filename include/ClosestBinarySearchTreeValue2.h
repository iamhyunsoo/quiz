class Solution272a	// Worst O(n)
{
	bool mbWillBeAllGreater = false;
public:
	std::vector<int> closestKValues(TreeNode *root, double target, int k)
	{
		std::deque<int> deq;
		this->inorder(deq, root, target, k);
		return std::vector<int>(&(deq.begin()), &(deq.end()));
	}
private:
	void inorder(std::deque<int>& deq, TreeNode*& root, double target, int k)
	{
		if ( !root ) { return; }
		this->inorder( deq, root->left, target, k );

		if (mbWillBeAllGreater)
		{
			// BREAK THIS WHOLE TRAVERSAL
			return;
		}

		if ( deq.size() == (size_t)k )
		{
			if ( std::abs(root->val - target) < std::abs(deq.front() - target) )
			{
				deq.pop_front();
				deq.push_back( root->val );
			}
			else
			{
				mbWillBeAllGreater = true;
				return;
			}
		}
		else
		{
			deq.push_back( root->val );
		}

		if (mbWillBeAllGreater)
		{
			// BREAK THIS WHOLE TRAVERSAL
			return;
		}

		this->inorder( deq, root->right, target, k );
	}
};

class Solution272b	// O(nLogn)
{
public:
	std::vector<int> closestKValues(TreeNode *root, double target, int k)
	{
		std::vector<int> values;
		this->GetInorder(root, values);

		std::sort(values.begin(), values.end(), 
		[&target](int const& a, int const& b)
		{
			return std::abs(target - a) < std::abs(target - b);
		});
									 // Constraint: k <= len(values)
		return std::vector<int>(values.begin(), values.begin() + k);
	}

private:
	void GetInorder 
	(
		TreeNode*& root,
		std::vector<int>& values
	)
	{
		if (!root)
		{
			return;
		}
		this->GetInorder(root->left, values);
		values.push_back(root->val);
		this->GetInorder(root->right, values);
	}
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
