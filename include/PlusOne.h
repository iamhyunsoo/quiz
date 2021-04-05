#include <vector>

std::vector<int> plusOne(std::vector<int>& digits)
{
    int pos = digits.size() - 1;
    digits[pos]++;

    while (pos >= 0)
    {
        if (digits[pos] == 10)
        {
            digits[pos] = 0;
            
            if (pos - 1 >= 0)
            {
                digits[pos-1]++;
            }
            else
            {
                digits.insert(digits.begin(), 1);
            }
        }
        pos--;
    }
    return digits;
}