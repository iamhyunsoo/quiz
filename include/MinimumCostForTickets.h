#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <vector>
#define BOTTOMUP
class Solution983 
{
public:
#ifdef BOTTOMUP
    int mincostTickets(std::vector<int> days, std::vector<int> costs)
    {
        int n = days.back();
        std::vector<int> dp(n+1, 0);
        std::unordered_set<int> st(std::make_move_iterator(days.begin()),std::make_move_iterator(days.end()));
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) != st.end())
            {
                dp[i] = std::min(
                    costs[0] + dp[std::max(i - 1, 0)],
                    std::min(costs[1] + dp[std::max(i - 7, 0)],
                    costs[2] + dp[std::max(i - 30, 0)])
                );                
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
#endif

#ifdef TOPDOWN
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs)
    {
        mN = days.back();
        mDP.assign(mN + 1, 0);
        std::unordered_set<int> st(std::make_move_iterator(days.begin()),std::make_move_iterator(days.end()));
        mDays = st;
        this->costs = costs;
        return helper(1);
    }

    int helper(int i)
    {
        if (i > mN) return 0;
        if (mDP[i]) return mDP[i];

        int ret {0};
        if (mDays.find(i) != mDays.end())
        {
            ret = std::min(
                costs[0] + helper(i + 1),
                std::min(
                    costs[1] + helper(i + 7),
                    costs[2] + helper(i + 30))
                );
        }
        else
        {
            ret = helper(i + 1);
        }

        mDP[i] = ret;
        return ret;
    }

private:
    std::vector<int> costs;
    std::vector<int> mDP;
    std::unordered_set<int> mDays;
    int mN;
#endif
};
