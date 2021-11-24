int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}