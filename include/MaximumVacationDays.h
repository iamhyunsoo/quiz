class Solution568 
{
public:
    int maxVacationDaysDP(vector<vector<int>>& flights, vector<vector<int>>& days)
    {
        std::vector<std::vector<int>> dp(days.size(), std::vector<int>(days[0].size()+1, 0));
        for (int week = days[0].size() - 1; week >= 0; week--)
        {
            for (int city = 0; city < days.size(); city++)
            {
                dp[city][week] = days[city][week] + dp[city][week+1];
                for (int dest = 0; dest < days.size(); dest++)
                {
                    if (flights[city][dest])
                    {
                        dp[city][week] = std::max(dp[city][week], days[dest][week] + dp[dest][week + 1]);
                    }
                }
            }
        }
        return dp[0][0];
    }

    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) 
    {
        mHistory.assign(flights.size(), std::vector<int>(days[0].size(), INT_MIN));
        return helper(flights, days, 0, 0);
    }

    int helper(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week)
    {
        if (week == days[0].size()) return 0;
        if (mHistory[city][week] != INT_MIN) return mHistory[city][week];

        int maxDays{ 0 };
        for (size_t i = 0; i < flights.size(); i++)
        {
            if (city == i || flights[city][i])
            {
                int vacation = days[i][week] + helper(flights, days, i, week + 1);
                maxDays = std::max(maxDays, vacation);
            }
        }
        mHistory[city][week] = maxDays;
        return maxDays;
    }
private:
    std::vector<std::vector<int>> mHistory;
};
