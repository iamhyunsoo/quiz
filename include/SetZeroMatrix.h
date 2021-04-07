#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) 
{
    bool isFirstColZero = false;
    int i {0};
    int j {0};

    int size = matrix.size();
    int len  = matrix[0].size();
    for (; i < size; i++)
    {
        if (!isFirstColZero && matrix[i][0] == 0)
        {
            isFirstColZero = true;
        }
        for (j = 1; j < len; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (i = 1; i < size; i++)
    {
        for (j = 1; j < len; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (j = 1; j < len; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (isFirstColZero)
    {
        for (i = 0; i < size; i++)
        {
            matrix[i][0] = 0;
        }
    }
}