
double myPow(double x, int n)
{
    double ans { 1 };
    int neg = n < 0 ? 1 : 0;

    while (n != 0)
    {
        if (n & 1)
        {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }   
    if (neg)
    {
        return 1 / ans;
    }
    return ans;
}