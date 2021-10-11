#include <vector>

std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k)
    {
        const int size = arr.size();
        double l = 0;
        double r = 1;
        while (l < r)
        {
            double m = (l + r) / 2;
            int cnt = 0;
            int a = 0;           // Temporary index 
            int b = 0;           // Temporary index
            double currMax = 0;  // Temporary value
            int j = 1;

            for (int i = 0; i < size; i++)
            {
                while (j < size && static_cast<double>(arr[i]) / arr[j] > m)
                {
                    j++;
                }
                
                if (j == size)
                {
                    break;
                }

                cnt += (size - j);
                if (currMax < static_cast<double>(arr[i]) / arr[j])
                {
                    currMax = static_cast<double>(arr[i]) / arr[j];
                    a = i;
                    b = j;
                }
            }

            if (cnt == k)
            {
                return { arr[a], arr[b] };
            }
            else if (cnt > k)
            {
                r = m;
            }
            else if (cnt < k)
            {
                l = m;
            }
        }
        return {};
    }
