#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
    public: 
        static int longestValidParentheses2(std::string s)
        {
            int len = s.length();
            int i {0};      //New start point when invalid parentheses happen;
            int answer {0}; //Max length so far;
            int p {0};      //Current valid parentheses so far; if it goes below 0, it means it's invalid;

            for (int j = 0; j < len; j++)
            {
                if (s[j] == '(')
                {
                    p++;
                }
                else if (s[j] == ')')
                {
                    p--;
                    if (p == 0)
                    {
                        answer = std::max(answer, j - i + 1);                        
                    }
                }

                if (p < 0)
                {
                    p = 0;
                    i = j + 1;
                }
            }

            p = 0;
            i = len - 1;
            for (int j = len - 1; j >= 0; j--)
            {
                if (s[j] == ')')
                {
                    p++;
                }
                else if (s[j] == '(')
                {
                    p--;
                    if (p == 0)
                    {
                        answer = std::max(answer, i - j + 1);                        
                    }
                }

                if (p < 0)
                {
                    p = 0;
                    i = j - 1;
                }
            }
            return answer;
        }

        static int longestValidParentheses(std::string s)
        {
            size_t size = s.size();
            if (size == 0) 
            {
                return 0;
            }
            int count {0};
            std::stack<char> stack;
            for (size_t i = 0; i < size; ++i)
            {                    cout << "I: " << i <<endl;

                char curr = s[i];
                if (curr == ')' || curr == ']' || curr == '}')
                {                    cout << "hmm "  << curr <<endl;

                    if (stack.size() == 0) 
                    {                    cout << curr <<endl;

                        continue;
                    }
                    if (curr == ')' && stack.top() == '(')
                    {                    cout << curr <<endl;

                        count += 2;                         // ) ( [ ( ) ) [ ] ] ) 
                      
                    }    
                    if (curr == ']' && stack.top() == '[')
                    {                    cout << curr <<endl;

                        count += 2;                         // ) ( [ ( ) ) [ ] ] ) 
                        
                    }    
                    if (curr == '}' && stack.top() == '{')
                    {                    cout << curr <<endl;

                        count += 2;                         // ) ( [ ( ) ) [ ] ] ) 
                    }    
                    stack.pop();
                }
                else
                {
                    cout << curr <<endl;
                    stack.push(curr);
                }
            }
            
            return count;
        }
};

