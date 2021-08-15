#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using std::vector;


//  vector<vector<std::string>> products = {{ "10", "d0", "d1" }, { "15", "EMPTY", "EMPTY" }, { "20", "d1", "EMPTY" }};
//  vector<vector<std::string>> discounts = {{"d0", "1", "27"}, {"d1", "2", "5"}, {"d2", "1", "34"}, {"d3", "1", "55"}, {"d4", "1", "34"}};
int findLowestPrice(vector<vector<std::string>> products, vector<vector<std::string>> discounts)
{
    int sum{ 0 };
    std::unordered_map<std::string, std::vector<int>> dict;
    for (auto& v : discounts)
    {
        for (int i = 1; i < v.size(); i++)
        {
            dict[v[0]].push_back(std::stoi(v[i]));
        }
    }

    for (int i = 0; i < products.size(); i++)
    {
        int price = std::stoi(products[i][0]);
        int best = price;
        for (int j = 1; j < products[i].size(); j++)
        {
            if (products[i][j] == "EMPTY") continue;

            auto& v = dict[products[i][j]];
            if (v[0] == 0)
            {
                best = std::min(best, v[1]);
            }
            else if (v[0] == 1)
            {
                best = std::min(best, (int)(price * (100 - v[1]) / 100) );
            }
            else if (v[0] == 2)
            {
                best = std::min(best, price - v[1]);
            }
        }
        sum += best;
    }

    return sum;
}
