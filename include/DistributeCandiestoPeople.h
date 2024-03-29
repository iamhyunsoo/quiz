    vector<int> distributeCandies(int candies, int num_people) 
    {
        std::vector<int> ret(num_people, 0);
        for (int i = 0; ; i++)
        {
            if (candies > (i + 1))
            {
                ret[i % num_people] += (i + 1);
                candies -= (i + 1);
            }
            else
            {
                ret[i % num_people] += candies;
                break;
            }
        }
        return ret;
    }
