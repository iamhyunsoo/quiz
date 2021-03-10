#include <string>
#include <stack>

class Solution
{
    public: 
        static bool isValid(std::string s)
        {
            size_t size = s.size();
            if (size == 0 || size == 1)
            {
                return 0;
            
            }
            std::stack<char> stack;
            for (size_t i = 0; i < size; ++i)
            {
                char curr = s[i];
                if (curr == ')' || curr == ']' || curr == '}')
                {
                    if (stack.size() == 0) 
                    {
                        return 0;
                    }
                    if (curr == ')' && stack.top() != '(')
                    {
                        return 0;
                    }    
                    if (curr == ']' && stack.top() != '[')
                    {
                        return 0;
                    }    
                    if (curr == '}' && stack.top() != '{')
                    {
                        return 0;
                    }    
                    stack.pop();
                }
                else
                {
                    stack.push(curr);
                }
            }
            
            return stack.size() ? false : true;
        }
};