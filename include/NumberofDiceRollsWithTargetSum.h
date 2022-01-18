class Solution
{
public:
	int numRollsToTarget(int n, int k, int target)
	{
		return helper(n, k, target);
	}
private:
	int helper(int n, int k, int target)
	{
		if (!n || target <= 0)
		{
			return n == target;
		}

		if (mDP[n][target])
		{
			return 	mDP[n][target] - 1;
		}

		int res{ 0 };
		for (int i = 1; i <= k; i++)
		{
			res = (res + helper(n - 1, k, target - i)) % 1000000007;
		}
		mDP[n][target] = res + 1;

		return res;
	}
private:
	int mDP[31][1001] = {};
};
