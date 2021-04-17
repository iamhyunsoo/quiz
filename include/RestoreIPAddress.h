#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{

private:
    vector<string> ans;

public:
    vector<string> restoreIpAddresses(string s)
    {
        string tmp {};
        help(s, tmp, 0, 0);
        return ans;
    } 
    void help(string& s, string& tmp, int pos, int cnt)
    {
        if (cnt == 4 && pos == s.size())
        {
            ans.push_back(tmp);
            return;
        }
        else
        {
            for (int i = pos; i < s.size(); i++)
            {
                if (cnt < 4 && i - pos < 3 && IsValid(s, pos, i))
                {
                    tmp += s.substr(pos, i - pos + 1);
                    cnt++;
                    if (cnt < 4)
                    {
                        tmp += '.';
                    }

                    help(s, tmp, i + 1, cnt);

                    if (cnt < 4)
                    {
                        tmp.pop_back();
                    }
                    cnt--;
                    for (int j = 0; j < i - pos + 1; j++)
                    {
                        tmp.pop_back();
                    }
                }
            }
        }
    }
    bool IsValid(string& s, int pos, int curr)
    {
        int ip = std::stoi(s.substr(pos, curr - pos + 1));
        if (s[pos] == '0' && pos != curr)
        {
            return false;
        }
        if (ip >= 0 && ip <= 255)
        {
            return true;
        }
        return false;
    }
};