class Solution {
    var ans: Int = 0
    func countArrangement(_ n: Int) -> Int {
        var visited = Array(repeating: false, count: n + 1)
        dfs(n, 1, &visited)
        return ans;
    }

    private func dfs(_ n: Int, _ pos: Int, _ visited: inout [Bool]) {
        if (pos > n) {
            self.ans += 1
            return
        }
        for i in 1...n {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true
                dfs(n, pos + 1, &visited)
                visited[i] = false
            }
        }
    }
}
