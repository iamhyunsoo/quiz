#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using std::vector;


class Solution 
{
public:
	vector<int> countSmaller(vector<int>& nums) 	// [5,2,6,1] -> [2, 1, 1, 0]
	{
		int size = nums.size();
		std::vector<int> ans(size, 0);

		int numMax = INT_MIN;
		int numMin = INT_MAX;
		
		for (auto const& n : nums)
		{
			numMax = std::max( numMax, n );
			numMin = std::min( numMin, n ); 
		}

		size = numMax - (--numMin) + 1;
		bits = new int[size]();

		int tmp {0};
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			tmp = nums[i] - numMin;
			ans[i] = GetValue(tmp - 1);
			UpdateArray(tmp, size);
		}

		return ans;
	}
private:
	int GetValue(int n)
	{
		int ret {0};
		while (n > 0)
		{
			ret += bits[n];
			n -= n & (-n);
		}
		return ret;
	}

	void UpdateArray(int n, const int& size)
	{
		while (n < size)
		{
			bits[n]++;
			n += n & (-n);
		}
	}

private:
	int* bits;
};