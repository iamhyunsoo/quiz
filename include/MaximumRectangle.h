#include <algorithm>
#include <vector>

using std::vector;
int maximalRectangle(vector<vector<char>>& matrix)
{
    int r = matrix.size();
    if (r == 0)
    {
        return 0;
    }
    int c = matrix[0].size();
    int ret {0};
    vector<int> histogram(c + 1, 0);

    for (int i = 0; i < r; i++)
    {
        vector<int> vec = {-1};
        for (int j = 0; j <= c; j++)
        {
            if (j < c && matrix[i][j] == '1')
            {
                histogram[j]++;
            }
            else
            {
                histogram[j] = 0;
            }
            
            while (vec.back() >= 0 && histogram[vec.back()] >= histogram[j])
            {
                int height = histogram[vec.back()];
                vec.pop_back();
                ret = std::max( ret, height * (j - vec.back() - 1));
            }
            vec.push_back(j);
        }
    }
    return ret;
}