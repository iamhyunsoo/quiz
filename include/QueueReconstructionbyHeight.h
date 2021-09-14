#include <algorithm>
#include <vector>

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        int size = static_cast<int>(people.size());
        mFreq = std::vector<int>(size + 1, 0);
        std::vector<std::vector<int>> ret(size, std::vector<int>());

        std::sort(people.begin(), people.end(), [](std::vector<int> const& a, std::vector<int> const& b)
            {
                if (a[0] != b[0])
                {
                    return a[0] < b[0];
                }
                else
                {
                    return a[1] > b[1];
                }
            }
        );

        for (int i = 2; i <= size; i++)
        {
            SetFrequency(i, 1, size);
        }

        for (int i = 0; i < size; i++)
        {
            int left  = 0;
            int right = size;
            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if (GetFrontNums(mid + 1) < people[i][1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            ret[left] = people[i];
            SetFrequency(left + 1, -1, size);
        }

        return ret;
    }

    int GetFrontNums(int idx)
    {
        int sum{ 0 };
        for (int i = idx; i > 0; i -= (i & -i))
        {
            sum += mFreq[i];
        }
        return sum;
    }

    void SetFrequency(int idx, int k, int const& size)
    {
        for (int i = idx; i <= size; i += (i & -i))
        {
            mFreq[i] += k;
        }
    }
private:
    std::vector<int> mFreq;
};
