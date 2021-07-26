#include <stack>
#include <vector>

class NestedInteger 
{
public:
	bool isInteger() const;
	int getInteger() const;
	const std::vector<NestedInteger>& getList() const;
};

class NestedIterator
{
public:
    NestedIterator(std::vector<NestedInteger>& nestedList) 
	{
		int size = nestedList.size();
		for (int i = size - 1; i >= 0; i--)
		{
			mStack.push(nestedList[i]);
		}
	}

    int next() 
	{
		auto ret = mStack.top().getInteger();
		mStack.pop();
		return ret;
    }

    bool hasNext() 
	{
		while (!mStack.empty()) {
			NestedInteger curr = mStack.top();
			if (curr.isInteger()) {
				return true;
			}

			mStack.pop();
			auto& adjs = curr.getList();
			int size = adjs.size();
			for (int i = size - 1; i >= 0; --i) {
				mStack.push(adjs[i]);
			}
		}

		return false;
	}
private:
	std::stack<NestedInteger> mStack;
};
