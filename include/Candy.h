#include <algorithm>
#include <numeric>
#include <vector>

int candy(std::vector<int>& ratings)
{
    const int size = ratings.size();
    std::vector<int> candies(size, 1);

    int i {1};
    for (; i < size; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (i = size - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }

    int sum = std::accumulate(candies.begin(), candies.end(), 0);
    return sum;
}