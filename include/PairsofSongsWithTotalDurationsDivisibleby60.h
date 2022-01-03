class Solution 
{
public:
    int numPairsDivisibleBy60TLE(vector<int>& time) //Time Limit Exceeded 
    {
        int cnt {0};
        for (int i  = 0; i < time.size(); i++)
        {
            for (int j = i+1; j < time.size(); j++)
            {
                if ((time[i] + time[j]) % 60 == 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int cnt {0};
        std::vector<int> arr(60, 0);
        for (auto const& t : time)
        {
            if (t % 60 == 0)
            {
                cnt += arr[0];
            }
            else
            {
                cnt += arr[60 - (t%60)];                
            }
            arr[t % 60]++;
        }
        return cnt;
    }
};
