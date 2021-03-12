#include <string>
#include <vector>

class Solution 
{
public:
    static std::vector<std::string> generateParenthesis(int n)
    {
        std::vector< std::string > ret;
        BackTrack(ret, std::string(""), 0, 0, n);
        return ret;
    }
    
    static void BackTrack(std::vector<std::string>& ans, std::string curr, int open, int close, int max)
    {
        if (curr.size() == max * 2)
        {
            ans.emplace_back(curr);
            return;
        }

        if (open < max)
        {
            BackTrack(ans, curr + std::string("("), open + 1, close, max);
        }
        if (close < open)
        {
            BackTrack(ans, curr + std::string(")"), open, close + 1, max);
        }
    }
};
