int maximizeSweetness(vector<int>& sweetness, int k) 
{

    const int numPeople = k + 1;
    // [1,2,3,4,5,6,7,8,9]
    int left = *min_element(sweetness.begin(), sweetness.end());
    int right= std::accumulate(sweetness.begin(), sweetness.end(), 0) / (numPeople);

    while (left < right)
    {
        int mid = (left + right + 1) / 2;

        int numOfChunk = 0;
        int tmpSumOfChunk = 0;
        for (auto const& n : sweetness)
        {
            tmpSumOfChunk += n;

            if (tmpSumOfChunk >= mid)
            {
                numOfChunk++;
                tmpSumOfChunk = 0;
            }
        }

        if (numOfChunk >= numPeople)
        {
            left = mid;    
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}
