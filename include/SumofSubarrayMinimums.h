class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long sum {0};
        int n = arr.size();
        std::stack<int> st;
        for (int i = 0; i <= n; ++i)
        {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
            {
                auto idx = st.top();
                st.pop();
                int leftBoundary = st.empty() ? -1 : st.top();
                long count = (i - idx) * (idx - leftBoundary) % 1000000007;
                sum += (arr[idx] * count) % 1000000007;
                sum %= 1000000007;
            }
            st.push(i);
        }
        return sum;
    }
};
