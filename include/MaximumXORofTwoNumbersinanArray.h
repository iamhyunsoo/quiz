
struct Trie
{
	Trie* mNext[2];
	Trie()
	{
		mNext[0] = nullptr;
		mNext[1] = nullptr;
	}
};

class Node
{
public:
	Node(int bits) : mBits{ bits } { mRoot = new Trie(); }
	
	void Insert(int num)
	{
		auto curr = mRoot;
		for (int i = mBits - 1; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (curr->mNext[bit] == nullptr)
			{
				curr->mNext[bit] = new Trie();
			}
			curr = curr->mNext[bit];
		}
	}

	int GetXOR(int num)
	{
		int ret{ 0 };
		auto curr = mRoot;
		for (int i = mBits - 1; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (curr->mNext[!bit])
			{
				ret += (1 << i);
				curr = curr->mNext[!bit];
			}
			else
			{
				curr = curr->mNext[bit];
			}
		}
		return ret;
	}

private:
	Trie* mRoot;
	int mBits;
};

class Solution 
{
public:
	int findMaximumXOR(std::vector<int>& nums) 
	{
		int maxNum = *(std::max_element(nums.begin(), nums.end()));
		int numBits = { 0 };
		while (maxNum != 0)
		{
			maxNum >>= 1;
			numBits++;
		}

		int ret{ 0 };
		Node* node = new Node(numBits);
		for (int const& num : nums)
		{
			node->Insert(num);
			ret = std::max(ret, node->GetXOR(num));
		}

		return ret;
	}
};
