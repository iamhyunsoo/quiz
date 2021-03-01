#include <string>


class Solution
{
public:
    static std::string ConvertToZigzag(std::string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        std::string ret = "";
        int n = s.size();
        int cycleLength = numRows * 2 - 2;      // How many elements in one cycle(one zigzag);

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; i + j < n; j += cycleLength)
            {
                ret += s[i + j];

                if (i != 0 && i != (numRows - 1) && (j + cycleLength - i) < n)
                {
                    ret += s[j + cycleLength - i];
                }
            }
        }
        return ret; 
    }
};
