class Solution 
{
public:
    bool checkRecord(std::string s) 
    {
        int As {0};
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] == 'A')
            {
                As++;
                if (As == 2)
                {
                    return false;
                }
            }
            else if (i >= 2 && s.substr(i-2, 3) == "LLL")
            {
                return false;
            }
        }
        return true;
    }
};
