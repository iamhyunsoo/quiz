
int sqrt(int n)
{
    long start {0};
    long end {n};
    long mid {0};
    long ans {0};

    while ( start <= end )
    {
        mid = (start + end) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return mid;
}