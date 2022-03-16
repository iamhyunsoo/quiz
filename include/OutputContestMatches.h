class Solution 
{
public:
    string findContestMatch(int n) 
    {
        std::vector<std::string> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = std::to_string(i + 1);
        }

        while (n > 1) 
        {
            for (int i = 0; i < n / 2; i++)
            {
                v[i] = "(" + v[i] + "," + v[n - i - 1] + ")"; 
            }
            n /= 2;
        }
        
        return v[0];
    }
};
