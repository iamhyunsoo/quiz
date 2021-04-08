#include <vector>

using namespace std;

template<typename T>
bool searchMatrix(vector<vector<T>>& matrix, T target)
{
    if (!matrix.size() || !matrix[0].size()) 
        return false;

    int l {0};
    int r = matrix.size() - 1;
    int mid {0};
    int row {0};

    while (l <= r)
    {
        mid = ( l + r ) / 2;
        if (matrix[mid].back() < target)
        {
            l = mid + 1;
        }
        else if (matrix[mid][0] > target)
        {
            r = mid - 1;
        }
        else
        {
            row = mid;
            break;
        }
    }

    l = 0;
    r = matrix[0].size() - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (matrix[row][mid] < target)
        {
            l = mid + 1;
        }
        else if (matrix[row][mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}