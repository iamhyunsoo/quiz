class Solution {
    int ans = 0;
public:
    int countArrangement(int n) {
        std::vector<bool> v(n + 1, false);
        calculate(n, 1, v);
        return ans;
    }
private:
    void calculate(int N, int pos, std::vector<bool>& visited) {
        if (pos > N)
        {
            ++this->ans;
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
};
