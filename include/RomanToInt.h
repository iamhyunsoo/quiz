#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        unordered_map<std::string, int> m{
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}};
        int sum{0};
        for (int i = 0; i < s.length(); i++)
        {
            std::string curr(1, s[i]);
            std::string next{};

            if (i < s.length() - 1)
            {
                next = (1, s[i + 1]);
            }

            if (m[curr + next])
            {
                sum += m[curr + next];
                i++;
                continue;
            }

            sum += m[curr];
        }
        return sum;
    }
};