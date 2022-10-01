class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int size = quantities.size();
        int l = 1;
        int r = *std::max_element(quantities.begin(), quantities.end());
        while (l < r)
        {
            int m = (l + r) / 2;
            auto cp = quantities;
            int i = 0;
            int type = 0;
            int stores = 0;
            for (auto const& x : quantities)
            {
                stores += (x + m - 1) / m;
            }
            if (stores > n)
            {
                l = m+1;
            }
            else 
            {
                r = m;
            }
        }
        return l;
    }
};
