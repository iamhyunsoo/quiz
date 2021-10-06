#include <string>
#include <vector>

using std::string;
using std::vector;

string getHint(string secret, string guess)
{
    int len = secret.length();
    if (len == 0)
    {
        return "0A0B";
    }

    std::vector<int> freq(len, 0);
    int bull {0};
    int cow {0};
    for (int i = 0; i < len; i++)
    {
        auto c1 = secret[i];
        auto c2 = guess[i];

        if (c1 == c2)
        {
            bull++;
        }
        else
        {
           if (freq[c1 - '0']++ < 0)
            {
                cow++;
            }
            if (freq[c2 - '0']-- > 0)
            {
                cow++;
            }
        }
    }
    return std::to_string(bull) + "A" + std::to_string(cow) + "B";
}