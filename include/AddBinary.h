#include <string>

std::string addBinary(std::string a, std::string b)
{
    int aLen = a.length();
    int bLen = b.length();

    std::string small = aLen < bLen ? a : b;
    std::string big   = aLen < bLen ? b : a;

    aLen = small.length();
    bLen = big.length();

    int sum {0};
    for (int i = aLen - 1, j = bLen - 1; j >= 0; j--, i--)
    {
        if (i >= 0)
        {
            sum += small[i] - '0';
        }
        sum += big[j] - '0';
        big[j] = sum % 2 + '0';
        sum /= 2;
    }
    if (sum)
    {
        big.insert(big.begin(), '1');
    }
    return big;
}