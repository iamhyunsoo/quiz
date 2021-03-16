#include <stdio.h>

int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;

    long d1 = dividend;
    long d2 = divisor;
    int bits = 1;
    int quo = 0;
    bool isMinus = false;

    if (d1 < 0)
    {
        d1 = -d1;
        isMinus = !isMinus;
    }

    if (d2 < 0)
    {
        d2 = -d2;
        isMinus = !isMinus;
    }

    while (d1 >= d2)
    {
       bits++;
       d2 <<= 1; 
    }

    while (bits--)
    {
        quo = quo * 2 + (d1 >= d2);
        if (d1 >= d2)
        {
            d1 -= d2;
        }
        d2 >>= 1;
    }

    if (quo > 2147483647l + isMinus)
    {
        printf("overflow\n\n");
        quo = 2147483647;
    }
    return isMinus ? -quo : quo;
}