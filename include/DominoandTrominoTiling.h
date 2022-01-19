#define BOTTOMUP
class Solution790
{
public:
    int numTilings(int n)
    {
#ifdef BOTTOMUP     
        if (n <= 2) 
        {  
            return n;
        }

        std::vector<long> fulls(n, 0);
        std::vector<long> partials(n, 0);
        fulls[0] = 1;
        fulls[1] = 2;
        partials[1] = 1;
        
        for (int i = 2; i < n; i++)
        {
            fulls[i] = (fulls[i - 2] + fulls[i - 1] + (2 * partials[i - 1])) % MOD;
            partials[i] = (fulls[i -2] + partials[i - 1]) % MOD;
        }

        return (int)fulls[n - 1];
#endif

#ifdef TOPDOWN
        return (int)GetFullCovered(n);
#endif
    }
private:
    long GetFullCovered(int n)
    {
        if (cacheF.find(n) != cacheF.end()) { return cacheF[n]; }
        int result {0};        
        if (n == 1) { result = 1; }
        else if (n == 2) { result = 2; }
        else
        {
            result = (GetFullCovered(n - 1) + GetFullCovered(n - 2) + (2 * GetPartialCovered(n - 1))) % MOD;
        }
        cacheF[n] = result;
        return result;
    }

    long GetPartialCovered(int n)
    {
        if (cacheP.find(n) != cacheP.end()) { return cacheP[n]; }
        int result {0};        
        if (n == 2) { result = 1; }
        else 
        {
            result = (GetFullCovered(n -2) + GetPartialCovered(n - 1)) % MOD;
        }
        cacheP[n] = result;
        return result;
    }
private:
    int MOD = 1000000007;
    std::unordered_map<int, long> cacheF;  
    std::unordered_map<int, long> cacheP;  
};
