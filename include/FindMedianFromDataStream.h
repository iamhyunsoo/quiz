#include <functional>
#include <queue>
#include <vector>

class MedianFinder
{
public:
	MedianFinder() {}

	void addNum(int num)
	{
		if (mMaxheap.empty() || mMaxheap.top() > num)
		{
			mMaxheap.push(num);
		}
		else
		{
			mMinheap.push(num);
		}

		if (mMaxheap.size() > mMinheap.size() + 1)
		{
			mMinheap.push(mMaxheap.top());
			mMaxheap.pop();
		}
		else if (mMinheap.size() > mMaxheap.size() + 1)
		{
			mMaxheap.push(mMinheap.top());
			mMinheap.pop();
		}
	}

	double findMedian()
	{
		if (mMaxheap.size() == mMinheap.size())
		{
			if (mMaxheap.empty()) return 0;
			else
			{
				return static_cast<double>(mMaxheap.top() + mMinheap.top()) / 2;
			}
		}
		else
		{
			return mMaxheap.size() > mMinheap.size() ? mMaxheap.top() : mMinheap.top();
		}
	}

private:
	std::priority_queue<int> mMaxheap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> mMinheap; 
};