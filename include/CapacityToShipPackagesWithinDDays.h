class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = 5 * 10000 * 500;
        while (l < r)
        {
            int m = (l + r) / 2;
            int c = 1;
            int acc = 0;
            for (int i = 0; i < weights.size(); ++i)
            {
                if (acc + weights[i] > m)
                {
                    ++c;
                    acc = 0;
                }
                acc += weights[i];
            }
            if (c > days)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
