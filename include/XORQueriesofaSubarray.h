class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        std::vector<int> ans;
        for (size_t i = 0; i < arr.size() - 1; ++i)
        {
            arr[i + 1] = arr[i] ^ arr[i + 1];
        }
        for (auto const& query : queries)
        {
            ans.push_back(query[0] == 0 ? arr[query[1]] : arr[query[1]] ^ arr[query[0] - 1]);
        }
        return ans;
    }
};
