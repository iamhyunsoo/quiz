class Solution1220 
{
public:
    int countVowelPermutation(int n) 
    {
        int MOD = 1000000007;
        std::vector<unsigned int> countA(n,1);           
        std::vector<unsigned int> countE(n,1);           
        std::vector<unsigned int> countI(n,1);           
        std::vector<unsigned int> countO(n,1);           
        std::vector<unsigned int> countU(n,1);           

        for (int i = 1; i < n; i++)
        {
            countA[i] = (countE[i - 1] + countI[i - 1] + countU[i - 1]) % MOD;
            countE[i] = (countA[i - 1] + countI[i - 1]) % MOD; 
            countI[i] = (countE[i - 1] + countO[i - 1]) % MOD;
            countO[i] = (countI[i - 1]) % MOD;
            countU[i] = (countI[i - 1] + countO[i - 1]) % MOD;
        }

        return (countA[n - 1] + countE[n - 1] + countI[n - 1] + countO[n - 1] + countU[n - 1]) % MOD; 
    }
};
