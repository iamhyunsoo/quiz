class Solution 
{
private:
    std::vector<int> mParents;
    std::vector<int> mRanks;
    std::vector<int> mSmallestPrimeFactors;
public:
    bool gcdSort(vector<int>& nums) 
    {
        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        mRanks.resize(sorted[sorted.size() - 1] + 1);
        setPrimeNumberOfEachParent(sorted[sorted.size() - 1] + 1);

        for (auto const& n : nums)
        {
            // divisors except 1 and itself
            std::vector<int> dv = getDivisors(n);
            for (size_t i = 0; i < dv.size(); ++i)
            {
                merge(dv[i], n);
            }
        }

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (getParent(nums[i]) != getParent(sorted[i]))
            {
                return false;
            }
        }
        return true;
    }
private:
    int getParent(int num)
    {
        return mParents[num] == num ? num : getParent(mParents[num]);
    }
    void merge(int a, int b)
    {
        auto ra = getParent(a);
        auto rb = getParent(b);
        if (mRanks[ra] > mRanks[rb])
        {
            mParents[rb] = ra;
        } 
        else if (mRanks[ra] < mRanks[rb])
        {
            mParents[ra] = rb;
        }
        else
        {
            mParents[rb] = ra;
            ++mRanks[ra];
        }
    }
    void setPrimeNumberOfEachParent(int size)
    {
        mParents.resize(size);
        mSmallestPrimeFactors.resize(size);
        std::iota(mParents.begin(), mParents.end(), 0); 
        std::iota(mSmallestPrimeFactors.begin(), mSmallestPrimeFactors.end(), 0); 

        for (int i = 2; i * i < size; ++i)
        {
            // not a prime number
            if (mSmallestPrimeFactors[i] != i)
            {
                continue;
            }
            for (int j = i * i; j < size; j += i)
            {
                mSmallestPrimeFactors[j] = i;
            }
        }
    }
    std::vector<int> getDivisors(int n)
    {
        std::vector<int> divisors; 
        while (n > 1)
        {
            divisors.push_back(mSmallestPrimeFactors[n]);
            n /= mSmallestPrimeFactors[n];
        }
        return divisors;
    }
};
