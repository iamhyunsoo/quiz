#include <stdint.h>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret {0};
        uint32_t pow {31};
        while (n)
        {
            ret += (n & 1) << pow--;
            n >>= 1;
        }
        return ret;
    }

public:
    uint32_t reverseBitsUsingArithmeticFunc(uint32_t n)
    {
        uint32_t ret {0};
        uint32_t pow {24};
        while(n)
        {
            ret += reverseByte(n & 0xff) << pow;
            n >>= 8;
            pow -= 8;
        }
        return ret;
    }

    uint32_t reverseByte(uint32_t byte)
    {
        return (byte * 0x0202020202 & 0x010884422010) % 1023;
    }
};