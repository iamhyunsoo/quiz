#include <vector>

int singleNumber(std::vector<int>& nums)
{
    int ones {0};
    int twos {0};
    int threes {0};

    for (int& x : nums)
    {
        twos = twos | (ones & x);
        ones = ones ^ x;
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }

    return ones;
}