#include <algorithm>
#include <vector>

class Solution312
{
public:
    int maxCoins(std::vector<int>& nums) 
    {
#ifdef __GNUC__
        int size = nums.size();
        int dp[size + 2][size + 2];
        int arr[size + 2];
        arr[0] = arr[size + 1] = 1;
        for (int i = 1; i < size + 1; i++) arr[i] = nums[i - 1];
        memset(dp, 0, sizeof(dp));
#elif _MSC_VER
        const int size = nums.size();
        std::vector<std::vector<int>> dp(size + 2, std::vector<int>(size + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
#endif

        for (int left = size; left >= 1; left--)
        {
            for (int right = left; right <= size; right++)
            {
                for (int k = left; k <= right; k++)
                {
#ifdef __GNUC__
                    int possibleMaximum = (arr[left - 1] * arr[k] * arr[right + 1]) + dp[left][k - 1] + dp[k + 1][right];
#elif _MSC_VER
                    int possibleMaximum = (nums[left - 1] * nums[k] * nums[right + 1]) + dp[left][k - 1] + dp[k + 1][right];
#endif
                    dp[left][right] = std::max(dp[left][right], possibleMaximum);
                }
            }
        }
        return dp[1][size];
    }
};
