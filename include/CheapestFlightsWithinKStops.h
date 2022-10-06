class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<long>> weights(2, std::vector<long>(n, INT_MAX));
        weights[0][src] = weights[1][src] = 0;
        for (int i = 0; i < k + 1; ++i)
        {
            for (auto const& flight: flights)
            {
                int SRC = flight[0];
                int DES = flight[1];
                int W = flight[2];

                long du = weights[1 - i&1][SRC];
                long dv = weights[1 & i][DES];
                if (du + W < dv)
                {
                    weights[1 & i][DES] = du + W;
                }
            }
        }
        return weights[1 & k][dst] == INT_MAX ? -1 : weights[1 & k][dst];
    }
};
