class Solution
{
public:
    int minCost(std::vector<int>& houses, std::vector<std::vector<int>>& cost, int m, int n, int target)
    {
        mDP.assign(m + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(target + 1, 0))); 
        int ret = helper(houses, cost, m, n, target, 0, 0);
        return ret < MAX_NUM ? ret : -1;
    }
private:
    int helper(std::vector<int>& houses, std::vector<std::vector<int>>& cost, int m, int n, int target, int curHouse, int curColor)
    {
        if (curHouse == m || target < 0)
        {
            if (target == 0)
            {
                return 0;
            }
            return MAX_NUM;
        }

        if (mDP[curHouse][curColor][target] != 0)
        {
            return mDP[curHouse][curColor][target];
        }

        int tmp = MAX_NUM;
        if (houses[curHouse] == 0)
        {
            for (int color = 1; color <= n; color++)
            {
                tmp = std::min(
                    tmp, 
                    helper(houses, cost, m, n, target - (curColor != color), curHouse + 1, color)+ cost[curHouse][color - 1]);
            }
        }
        else
        {
            tmp = helper(houses, cost, m, n, target - (houses[curHouse] != curColor), curHouse + 1, houses[curHouse]); 
        }

        mDP[curHouse][curColor][target] = tmp;
        return tmp;
    }

private:
    std::vector<std::vector<std::vector<int>>> mDP;
    int MAX_NUM = 100000000;
};
