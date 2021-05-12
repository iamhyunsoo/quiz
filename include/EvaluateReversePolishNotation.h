#include <stack>
#include <string>
#include <vector>

int evalRPN(std::vector<std::string>& tokens)
{
    int x {0};
    int y {0};
    std::stack<int> st;
    for (auto& token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            y = st.top();
            st.pop();
            x = st.top();
            st.pop();

            if (token == "+")
            {
                st.push(x + y);
            }
            else if (token == "-")
            {
                st.push(x - y);
            }
            else if (token == "*")
            {
                st.push(x * y);
            }
            else if (token == "/")
            {
                st.push(x / y);
            }
        }
        else
        {
            st.push(stoi(token));
        }
    }      
    return st.top();
}