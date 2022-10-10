class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int bestSum = arr[0];
        int currSum = arr[0];
        int n = arr.size();
        int mod = 1e9+7;
        int64_t sum = std::accumulate(arr.begin(), arr.end(), 0);
        for (int i = 1; i < n * std::min(k, 2); ++i)
        {
            currSum = std::max(arr[i % n], arr[i % n] + currSum);
            bestSum = std::max(bestSum, currSum);
        }
        return std::max<int64_t>({0, bestSum,  sum * std::max(0, (k - 2)) + bestSum}) % mod;
    }
};
