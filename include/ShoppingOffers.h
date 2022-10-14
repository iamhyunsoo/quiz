class Solution {
    std::map<std::vector<int>, int> m;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return getMinimumCosts(price, special, needs);
    }
private:
    int getMinimumCosts(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        if (m.find(needs) != m.end()) 
        {
            return m[needs];
        }
        int costs = getCosts(price, needs);
        for (auto const& offer : special)
        {
            std::vector<int> cp = needs;
            size_t i = 0;
            for (; i < cp.size(); ++i)
            {
                if (cp[i] - offer[i] < 0) { break; }
                cp[i] -= offer[i];
            }
            if (i == cp.size())
            {
                costs = std::min(costs, offer[i] + getMinimumCosts(price, special, cp));
            }
        }
        m[needs] = costs;
        return costs;
    }

    int getCosts(std::vector<int>& price, std::vector<int>& needs)
    {
        int total {0};
        for (size_t i = 0; i < price.size(); ++i)
        {
            total += price[i] * needs[i];
        }
        return total;
    }
};
