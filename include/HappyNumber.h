
#include <unordered_set>
bool isHappy(int n)                 //More memory needed
{
    std::unordered_set<int> s;
    while (n != 1)
    {
        if (s.find(n) == s.end())
        {
            s.insert(n);
        }
        else
        {
            return false;
        }

        int sum {0};
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        n = sum;
    }
    return true;
}

class Solution
{
public:
    bool isHappy(int n) //More time needed (floyd algorithm)
    {
        int slow = next(n);
        int fast = next( next(n) );

        while (slow != fast)
        {
            slow = next(slow);
            fast = next( next(fast) );
        }
        return fast == 1;
    }
private:
    int next(int n)
    {
        int sum {0};
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};