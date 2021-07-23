#include <algorithm>
#include <unordered_map>
#include <utility>
#include <queue>
#include <vector>

class Solution1		// O(nLog(k)) using minimum priority queue
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, const int K) 
	{
		std::unordered_map<int, int> m;
		std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, cmp> pq;
		std::vector<int> ret;
		
		for (auto const& n : nums)
		{
			m[n]++;
		}

		for (auto const& i : m)
		{
			pq.push({i.first, i.second});
			if (pq.size() > K)
			{
				pq.pop();
			}
		}

		while (!pq.empty())
		{
			ret.push_back(pq.top().first);
			pq.pop();
		}

		return ret;
	}
private:
	struct cmp
	{
		bool operator()(std::pair<int, int> const& lhs, std::pair<int, int> const& rhs) const
		{
			return lhs.second > rhs.second;
		}
	};
};


class Solution2		// O(n) using quick sort
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, const int k) 
	{
		std::vector<int> ret(k);
		for (auto const& n : nums)
		{
			mMap[n]++;
		}

		for (auto const& p : mMap)
		{
			mNumber.push_back(p.first);
		}

		auto mapSize = mMap.size();
		quickSort(0, mapSize - 1, mapSize - k);
		std::copy(mNumber.begin() + (mapSize - k), mNumber.end(), ret.begin());
		return ret;
	}

private:
	void quickSort(int left, int right, int kth)
	{
		if (left == right) return;

		int partition = GetPartition(left, right);

		if (kth == partition) return;
		else if (kth > partition)
		{
			quickSort(partition + 1, right, kth);
		}
		else if (kth < partition)
		{
			quickSort(left, partition - 1, kth);
		}
	}

	int GetPartition(int left, int right)
	{
		int pivotFreq = mMap[mNumber[right]];
		int i = left;
		for (int j = left; j < right; j++)
		{
			if (mMap[mNumber[j]] < pivotFreq)
			{
				std::swap(mNumber[j], mNumber[i]);
				i++;
			}
		}
		std::swap(mNumber[i], mNumber[right]);
		return i;
	}

private:
	std::unordered_map<int, int> mMap;
	std::vector<int> mNumber;
};