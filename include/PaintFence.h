class Solution 
{
public:
    int numWays(int n, int k) 
    {
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        int twoBack = k;
        int oneBack = k * k;
        int ways {0};

        for (int i = 2; i < n; i++)
        {
            ways = (k - 1) * (twoBack + oneBack);
            twoBack = oneBack;
            oneBack = ways;
        }
        return ways;
    }
};
