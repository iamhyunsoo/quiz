int lastRemaining(int n) 
{
    int head = 1;
    int step = 1;
    bool dir = true;
    while (n > 1)
    {
        if (dir)
        {
            head += step;
        }
        else
        {
            head += (n % 2) ? step : 0;
        }

        step *= 2;
        n /= 2;
        dir = !dir;
    }
    return head;
}
