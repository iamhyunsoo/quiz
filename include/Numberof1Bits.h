#include <stdint.h>

int hammingWeight(uint32_t n)
{
    uint32_t ret {0};
    uint32_t mask {1};
    for (uint8_t i = 0; i < 32; i++)
    {
        if (n & mask)
        {
            ret++;
        }
        mask <<= 1;
    }
    return ret;
}