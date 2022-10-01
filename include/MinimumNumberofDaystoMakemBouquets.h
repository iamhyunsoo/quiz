class Solution 
{
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if (m * k > n) { return -1; }
        int l = 1;
        int r = *std::max_element(bloomDay.begin(), bloomDay.end()) * 2;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int bouquet = 0;
            int straight = 0;
            for (int i = 0; i < n; ++i)
            {
                if (bloomDay[i] > mid)
                {
                    straight = 0;
                }
                else if (++straight >= k)
                {
                    straight = 0;
                    ++bouquet;
                }
            }
            if (bouquet < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
