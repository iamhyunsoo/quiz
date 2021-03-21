#include <string>

using namespace std;

class Solution
{
    public:
    string solve(string s)
    {
        string tmp {};
        char ch = s[0];
        int count {1};

        for (size_t i = 1; i < s.length(); i++)
        {
            if (ch == s[i])
            {
                count++;
            }
            else
            {
                tmp += to_string(count);
                tmp.push_back(ch);
                ch = s[i];
                count = 1;  
            }
        }
        tmp += to_string(count);
        tmp.push_back(ch);

        return tmp;        
    }

    string countAndSay(int n)
    {
        string ret = "1";

        for (int i = 0; i < n - 1; i++)
        {
            ret = solve(ret);
        }
        return ret;
    }
};