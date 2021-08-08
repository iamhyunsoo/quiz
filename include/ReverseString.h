#include <algorithm>
#include <vector>

void reverseString(std::vector<char>& s) 
{
    int j = s.size() - 1;
    int i = 0;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}
