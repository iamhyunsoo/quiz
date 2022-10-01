double minmaxGasDist(vector<int>& stations, int k) 
{
    int n  = stations.size();
    double l = 0;
    double r = stations[n - 1] - stations[0];
    while (l + 1e-6 < r)
    {
        double m = (l + r) / 2;
        int newStation = 0;
        for (size_t i = 0; i < n - 1; ++i)
        {
            newStation += ceil((stations[i + 1] - stations[i]) /m) - 1;
        }
        if (newStation > k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}
