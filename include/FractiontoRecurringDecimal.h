#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (!numerator)
        return "0";

    string ans {};
    if (numerator > 0 ^ denominator > 0)
    {
        ans += '-';
    }

    long numer = labs(numerator);
    long denomi= labs(denominator);
    long remainder = numer % denomi;

    ans += std::to_string(numer / denomi);

    if (!remainder)
    {
        return ans;
    }

    ans += '.';
    unordered_map<long, int> map;
    while (remainder)
    {
       if (map.find(remainder) != map.end())
       {
           ans.insert(map[remainder], "(");
           ans += ')';
           break;
       }
       map[remainder] = ans.size();
       ans += to_string(remainder * 10 / denomi);
       remainder = (remainder * 10) % denomi;
    }

    return ans;
}