#include <algorithm>
#include <vector>

void mergeSortedArray(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int pos = m + n - 1;
    m--;
    n--;

    while (m >= 0 && n >= 0)
    {
        const int num1 = nums1[m];
        const int num2 = nums2[n];
        nums1[pos] = std::max(num1, num2);
        if (num1 > num2)
        {
            m--;
        }
        else
        {
            n--;
        }
        pos--;
    }
    while (n >= 0)
    {
        nums1[pos] = nums2[n];
        pos--;
        n--;
    }
}
