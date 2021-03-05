#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static string longestCommonPrefixBetter(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        int i = 0;
        string s = strs[0];

        while (i >= 0)
        {
            for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
            {
                if (s[i] == '\0' || (*it)[i] == '\0' || s[i] != (*it)[i])
                {
                    return (s.substr(0, i));
                }
            }
            i++;
        }
        return "";
    }

    static string longestCommonPrefix(vector<string> &strs)
    {

        if (strs.size() == 1)
        {
            return strs[0];
        }
        else if (strs.empty())
        {
            return std::string("");
        }

        std::string curr{};
        std::string prev{};

        for (int i = 0; i < std::min(strs[0].length(), strs[1].length()); i++)
        {
            if (strs[0][i] != strs[1][i])
            {
                break;
            }
            curr.append(1, strs[0][i]);
        }

        for (int i = 1; i < strs.size(); i++)
        {
            if (curr.length() == 0)
            {
                return std::string("");
            }

            prev = curr;
            curr = {};
            for (int j = 0; j < prev.length(); j++)
            {
                if (strs[i][j] != prev[j])
                {
                    break;
                }
                curr.append(1, prev[j]);
            }
        }
        return curr;
    }
};