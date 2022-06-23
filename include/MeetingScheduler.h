class Solution 
{
    using T = std::vector<int>;
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        auto cmp = [](std::vector<int> const& a, std::vector<int> const& b){
            return a[0] > b[0]; 
        };
        std::priority_queue<T, std::vector<T>, decltype(cmp)> que(cmp);
        
        for (auto&& slot : slots1)
        {
            if (slot[1] - slot[0] >= duration)
            {
                que.push(std::move(slot));
            }
        }
        
        for (auto&& slot : slots2)
        {
            if (slot[1] - slot[0] >= duration)
            {
                que.push(std::move(slot));
            }
        }

        while (que.size() > 1)
        {
            auto s1 = que.top();
            que.pop();
            auto s2 = que.top();
            
            if (s1[1] >= s2[0] + duration)
            {
                return std::vector<int>{ s2[0], s2[0] + duration};
            }
        }
        
        return std::vector<int>();
    }
};
