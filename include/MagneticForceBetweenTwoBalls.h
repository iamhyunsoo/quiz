class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = position.back() - position[0];
        while (l < r)
        {
            int mid = l + (r - l) / 2 + 1;
            int cnt = 1;
            int curPos = position[0];
            for (size_t i = 1; i < position.size(); ++i)
            {
                if (position[i] - curPos >= mid)
                {
                    ++cnt;
                    curPos = position[i];
                }
            }
            if (cnt >= m)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};
