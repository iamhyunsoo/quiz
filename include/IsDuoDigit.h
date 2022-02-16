// If a digit s has more than 2 numbers return "n", otherwise "y"
// EX. s = 1222 return "y". 
// EX. s = 123 return "n" as there are 1,2 and 3.
// EX. s = 252525 return "y" because there are only two numbers, 2 and 5.
// EX. s = 1111 return "y".
#include <unordered_set>
#include <string>
std::string isDuoDigit(int s)
{
    std::unordered_set<char> st;
    std::string strNum = std::to_string(s);

    for (char const& c : strNum)
    {
        st.insert(c);
    }

    return st.size() > 2 ? "n" : "y";
}
