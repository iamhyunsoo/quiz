
int rangeBitwiseAndPrefer(int left, int right) 
{
    int tmp = left ^ right;     //When there's the first difference between two numbers, it will be marked '1'
                                //EX: [ 0000 1111, 0000 1011 ]  -> x = a ^ b -> x = 0000 0100. 
                                //We'll exclude all after the '1', which is 2^2 above.
    tmp |= tmp >> 1;
    tmp |= tmp >> 2;
    tmp |= tmp >> 4;
    tmp |= tmp >> 8;
    tmp |= tmp >> 16;

    return left & ~tmp;
}                           

int rangeBitwiseAnd(int left, int right) 
{
    int ret {0};
    for (int i = 30; i >= 0; i--)
    {
        if (left & (1 << i) != right & (1 << i))
        {
            break;
        }
        else
        {
            ret |= left & 1 << i;
        }
    }
    return ret;
}

