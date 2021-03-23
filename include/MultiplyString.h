#include <algorithm>
#include <string>

std::string multiply(std::string num1, std::string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return std::string("0");
    }

    std::string ans {};
    int n1 = num1.length();
    int n2 = num2.length();

    if (n1 < n2)
    {
        std::swap(num1, num2);
        std::swap(n1, n2);
    }

    std::reverse(std::begin(num1), std::end(num1));
    std::reverse(std::begin(num2), std::end(num2));

    int mul {0};        //temporary value of multiplication
    int rem {0};        //remainder
    int sum {0};            
    for (int i = 0; i < n2; i++)
    {
        int j {0};
        int carry {0};
        for(; j < n1; j++)
        {
            mul = (num1[j] - '0') * (num2[i] - '0') + carry;
            rem = mul % 10;
            carry = mul / 10;

            if (ans.length() < i + j + 1)
            {
                ans.push_back(char(rem + '0'));
            }
            else
            {
                sum = ans[i + j] - '0' + rem;
                ans[i + j] = sum % 10 + '0';
                carry += sum / 10;
            }
        }

        if (carry)
        {
            ans.push_back(char(carry + '0'));
        }
    }
    std::reverse(std::begin(ans), std::end(ans));
    return ans;
}