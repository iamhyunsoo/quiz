/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution
{
public:
    int findCelebrity(int n)    // Greedy O(n)
    {        
        int possible = 0;
        for (int i = 0; i < n; i++)
        {
            if (knows(possible, i))
            {
                possible = i;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (i == possible) continue;
            
            if (knows(possible, i) || !knows(i, possible))
            {
                return -1;
            }
        }
        
        return possible;
    }
};
