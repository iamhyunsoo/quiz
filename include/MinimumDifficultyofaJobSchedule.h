class Solution1335 
{
public:
	int minDifficulty(vector<int>& jobDifficulty, int d)	// BOTTUM UP 
	{
		if (jobDifficulty.size() < d) return -1;

		int n = jobDifficulty.size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(d + 1, INT_MAX));
		dp[n - 1][d] = jobDifficulty[n - 1];

		for (int i = n - 2; i >= 0; i--)
		{
			dp[i][d] = std::max(jobDifficulty[i], dp[i + 1][d]);
		}

		for (int day = d - 1; day > 0; day--)
		{
			for (int i = day - 1; i < n - (d - day); i++)
			{
				int highest{ 0 };
				for (int j = i; j < n - (d - day); j++)
				{
					highest = std::max(highest, jobDifficulty[j]);
					dp[i][day] = std::min(dp[i][day], highest);
				}
			}
		}
		return dp[0][1];
	}

#ifdef TLE
	int minDifficulty(vector<int>& jobDifficulty, int d)	//TOP-DOWN Time limit exceeded
	{
		mN = jobDifficulty.size();
		if (mN < d) return -1;

		mDays = d;
		mJobDifficulty = jobDifficulty;
		mDP.assign(mN, std::vector<int>(d + 1, 0));

		mHardestJob.assign(mN, 0);
		int hardest{ 0 };
		for (int i = jobDifficulty.size() - 1; i >= 0; i--)
		{
			hardest = std::max(hardest, jobDifficulty[i]);
			mHardestJob[i] = hardest;
		}

		return helper(0, 1);
	}

	int helper(int ithJob, int d)
	{
		if (d == mDays) return mHardestJob[ithJob];

		if (mDP[ithJob][d] == 0)
		{
			int highest{ 0 };
			int minSum{ INT_MAX };
			for (int j = ithJob; j < mN - (mDays - d); j++)
			{
				highest = std::max(highest, mJobDifficulty[j]);
				minSum = std::min(minSum, highest + helper(j + 1, d + 1));
			}
			mDP[ithJob][d] = minSum;
		}
		return mDP[ithJob][d];
	}
private:
	int mN;
	int mDays;
	vector<int> mJobDifficulty;
	vector<int> mHardestJob;
	std::vector<std::vector<int>> mDP;
#endif
};
