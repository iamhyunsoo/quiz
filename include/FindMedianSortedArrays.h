#include <vector>

class Solution {
public:
    static double findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2)
    {
        int a = num1.size();
        int b = num2.size();

        int beforeMedian{ 0 };
        int Median{ 0 };

        int len = (a + b) / 2;

        int currA{ 0 };
        int currB{ 0 };
        
        for (int i = 0; i <= len; ++i)
        {
            if (currA < a && currB < b)
            {
                if (num1[currA] > num2[currB])
                {
                    beforeMedian = Median;
                    Median = num2[currB++];
                }
                else
                {
                    beforeMedian = Median;
                    Median = num1[currA++];
                }
            }
            else if (currA < a)
            {
                beforeMedian = Median;
                Median = num1[currA++];
            }
            else
            {
                beforeMedian = Median;
                Median = num2[currB++];
            }
        }

        if ((a + b) & 1)
        {
            return Median;
           
        }
        else
        {
            return ( static_cast<double>(beforeMedian) + static_cast<double>(Median) ) / 2;
        }

        return -1;   //Error, might be unsorted arrays
    }
};
