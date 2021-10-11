#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class EvaluateDivision
{
public:
    std::vector<double> calcEquation
    (
        std::vector<std::vector<std::string>>& equations, 
        std::vector<double>& values, 
        std::vector<std::vector<std::string>>& queries
    )
    {
        int size = queries.size();
        std::vector<double> ret(size, 0);
        std::unordered_map<std::string, std::unordered_map<std::string, double>> table;
        for (int i = 0; i < values.size(); i++)
        {
            std::string& a = equations[i][0];
            std::string& b = equations[i][1];

            table[a].insert({ b, values[i] });
            table[b].insert({ a, 1 / values[i] });
        }

        for (int i = 0; i < size; i++)
        { 
            std::unordered_set<std::string> visited;
            ret[i] = GetResult(table, visited, queries[i][0], queries[i][1]);
        }
        return ret;
    }

private:
    double GetResult
    (
        std::unordered_map<std::string, std::unordered_map<std::string, double>>& table,
        std::unordered_set<std::string>& visited,
        std::string const& a,
        std::string const& b
    )
    {
        auto it = table.find(a);
        if (it == table.end())
        {
            return -1;
        }

        if (it->second.find(b) != it->second.end())
        {
            return it->second.find(b)->second;
        }

        visited.insert(a);
        for (auto const& sub : it->second)
        {
            if (visited.find(sub.first) == visited.end())
            {
                double ret = GetResult(table, visited, sub.first, b);
                if (ret != -1)
                {
                    return ret * sub.second;
                }
            }
        }

        return -1;
    }
};
