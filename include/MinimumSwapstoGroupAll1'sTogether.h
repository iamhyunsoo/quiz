int minSwaps(vector<int>& data) 
{
    int left {0};
    int right {0};
    int totalOnes = std::accumulate(data.begin(), 
                                    data.end(), 0);
    int maxConsecutiveOnes {0};
    int currentOnes {0};

    while (right < data.size())
    {
        currentOnes += data[right++];
        if (right - left > totalOnes)
        {
            currentOnes -= data[left++];
        }
        maxConsecutiveOnes = std::max(
                                  maxConsecutiveOnes,
                                  currentOnes);

    }

    return totalOnes - maxConsecutiveOnes;
}
