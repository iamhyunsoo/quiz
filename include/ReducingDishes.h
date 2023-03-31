class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end());
        int mx {0};
        int n = satisfaction.size();
        for (int i = 0; i < n; ++i)
        {
            int tmp {0};
            int k {1};
            for (int j = (n - i - 1); j < n; ++j)
            {
                tmp += (k++ * satisfaction[j]);
            }
            mx = std::max(mx, tmp);
        }
        return mx;
    }
};
