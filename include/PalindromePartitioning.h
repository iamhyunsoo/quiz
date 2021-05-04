#include <string>
#include <vector>

using std::string;
using std::vector;

class S
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<vector<bool>> dp (s.length(), vector<bool>(s.length(), false));
        vector<string> curr;
        help(0, s, curr, dp, ans);
        return ans;
    }

private:
    void help(int start, string& s, vector<string>& curr, vector<vector<bool>>& dp, vector<vector<string>>& ans)
    {
        if (start == s.length())
        {
            ans.push_back(curr);
            return;
        }
        
        for (int end = start; end < s.length(); end++)
        {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]) )
            {
                dp[start][end] = true;
                curr.push_back(s.substr(start, end - start + 1));
                help(end + 1, s, curr, dp, ans);
                curr.pop_back();
            }
        }
    }
};