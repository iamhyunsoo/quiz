class Solution 
{
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) // PASSED
    {
        std::string strN = std::to_string(n);
        size_t len = strN.length();
        size_t numDigits = digits.size();
        std::vector<int> dp(len+1, 0);
        dp[len] = 1;
        
       
        for (int i = len; i >= 0; i--)
        {
            int num = strN[i] - '0';
            for (auto const& digit : digits)
            {
                int intDigit = std::stoi(digit);
                if (num > intDigit)
                {
                    dp[i] += std::pow(numDigits, len - 1 - i);   
                }
                else if (num == intDigit)
                {
                    dp[i] += dp[i+1];
                }
            }
        }

        
        for (size_t i = 1; i < len; i++)
        {
            dp[0] += std::pow(numDigits, i);
        }
        
        return dp[0];
    }
};

class Solution777
{
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) // TIME LIMIT EXCEEDED
    {
        auto len = digits.size();                           // TIME LIMIT EXCEEDED
        
        int lenOfN {0};                                     // TIME LIMIT EXCEEDED
        auto tmp = n;
        while (tmp > 0)                                     // TIME LIMIT EXCEEDED
        {
            tmp /= 10;
            lenOfN++;
        }
        
        int output {0};
        for (size_t i = 1; i < lenOfN; i++)
        {
            output += std::pow(len, i);
        }
        
        std::string leastMaxLenNum = "";
        
        helper(digits, leastMaxLenNum, n, lenOfN, output);
        return output;
    }
    
    void helper(vector<string>& digits, std::string& curr, int n, int lenOfN, int& cnt)
    {
        long currNum = curr.length() ? std::stol(curr) : 0;
        if (currNum > n)
        {
            return;
        }
        
        if (curr.length() == lenOfN)
        {
            if (currNum <= n)
            {
                cnt++;
            }
            return;
        }
        
        for (size_t i = 0; i < digits.size(); i++)
        {
            curr += digits[i];
            helper(digits, curr, n, lenOfN, cnt);
            curr.pop_back();
        }
    }
};
