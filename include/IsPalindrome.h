

class Solution 
{
public:
    static bool isPalindrome(int x) 
    {
        int revertedNumber {0};
        
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        else
        {  
            int tmp = x;
            while(tmp) 
            {
                revertedNumber = (revertedNumber * 10) + (tmp % 10);
                tmp /= 10;
            }
        }
        return x == revertedNumber;
    }
};