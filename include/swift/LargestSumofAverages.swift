class Solution {
    func largestSumOfAverages(_ nums: [Int], _ k: Int) -> Double {
        let n = nums.count
        var dp = Array(repeating: Array(repeating: 0.0, count: k+1), count: n+1)
        var sum: Double = 0
        nums.enumerated().forEach {
            sum += Double($0.element)
            dp[$0.offset + 1][1] = sum / Double($0.offset + 1)
        }
        return getPartitionSumDfs(n, k, nums, &dp)
    }

    private func getPartitionSumDfs(_ n: Int, _ k: Int, _ nums: [Int], _ dp: inout [[Double]]) -> Double {
        if dp[n][k] > 0 {
            return dp[n][k]
        }
        if (n < k) {
            return 0
        }
        var sum: Double = 0
        for i in stride(from: (n-1), to: 0, by: -1) {
            sum += Double(nums[i])
            dp[n][k] = max(dp[n][k], (sum / Double(n - i)) + getPartitionSumDfs(i, k-1, nums, &dp))
        }
        return dp[n][k]
    }
}
