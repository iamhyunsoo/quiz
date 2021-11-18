    int heightChecker(vector<int>& heights) 
    {
        //heights  = [1, 1, 4, 2, 1, 3]
        //expected = [1, 1, 1, 2, 3 ,4]
        //heights[i] != expected[i]
        
        auto expected = heights;
        std::sort(expected.begin(), expected.end());  //expected = [1, 1, 1, 2, 3 ,4]
        
        int cnt {0};
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != expected[i])
            {
                cnt++;
            }
        }
        
        return cnt;
    }
