#include <vector>

using std::vector;

vector<int> grayCode(int n)
{
    vector<int> v(1, 0);
    int size {0};
    for (int i = 0; i < n; i++)
    {
        size = v.size();
        for (int j = size - 1; j >= 0; j--)
        {
            v.push_back(v[j] | (1 << i));
        }   
    }
    return v;
}

