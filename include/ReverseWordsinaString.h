#include <string>
#include <stack>

std::string reverseWords(std::string s)
{
    if (s.length() == 0)
    {
        return s;
    }

    std::stack<std::string> stack;
    for (int i = 0; i < s.length(); i++)
    {
        std::string tmp {""};
        if (s[i] == ' ')
        {
            continue;
        }
        while (i < s.length() && s[i] != ' ')
        {
            tmp += s[i++];
        }
        stack.push(tmp);
    }
    std::string ans {""};
    while (!stack.empty())
    {
        ans += stack.top();
        stack.pop();

        if (!stack.empty())
        {
            ans += " ";
        }
    }
    return ans;
}