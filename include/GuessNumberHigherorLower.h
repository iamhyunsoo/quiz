    int guessNumber(int n) 
    {
        int low = 1;
        long high = n;
        while(high>=low)
        {
            int mid = (low+high)/2;
            if(guess(mid)==-1)
            {
                high = mid-1;
            }
            else if(guess(mid)==0)
            {
                return mid;
            }
            else 
            {
                low = mid+1;
            }
        }
        return 0;
    }
