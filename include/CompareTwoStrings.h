#include <string>

// INSERT, DELETE by at most 1 EX) BAY == EBAY or CARS == CAR
// SWAP only 2 characters. EX) FROM == FORM
// If two strings are the same, EQUAL
// IMPOSSIBLE, if all of ways above can't be applied.
string CompareTwoStrings(string S, string T)  
{

    int len1 = S.length();
    int len2 = T.length();

    int diff = abs(len1 - len2);
    if (diff > 1)
    {
        return "IMPOSSIBLE";
    }
    if (S.compare(T) == 0)
    {
        return "EQUAL";
    }

    if (diff == 1)
    {
        for (int i = 0; i < len1 < len2 ? len1 : len2; i++)
        {
            if (S[i] != T[i])
            {
                if (len1 < len2)
                {
                    if (S.substr(i) == T.substr(i + 1))
                    {
                        std::string tmp = "INSERT ";
                        tmp += T[i];
                        return tmp;
                    }
                }
                else
                {
                    if (S.substr(i + 1) == T.substr(i))
                    {
                        std::string tmp = "REMOVE ";
                        tmp += S[i];
                        return tmp;
                    }
                }
            }
        }
    }

    else if (diff == 0)
    {
        int firstIdx{ -1 };
        int secondIdx{ -1 };
        for (int i = 0; i < len1; i++)
        {
            if (S[i] != T[i] && firstIdx == -1)
            {
                firstIdx = i;
            }
            else if (S[i] != T[i] && firstIdx != -1 && secondIdx == -1)
            {
                secondIdx = i;
            }
            else if (S[i] != T[i] && firstIdx != -1 && secondIdx != -1)
            {
                return "IMPOSSIBLE";
            }
        }
        if (firstIdx != -1 && secondIdx != -1)
        {
            std::string tmp = "SWAP ";
            tmp += S[firstIdx];
            tmp += " ";
            tmp += S[secondIdx];
            return tmp;
        }
        return "IMPOSSIBLE";
    }
}
