#include <vector>

void rotate(std::vector<std::vector<int>>& matrix)
{
    size_t size = matrix.size();
    int top {0};
    int bottom = (int)size - 1;
    int left {0};
    int right = (int)size - 1;

    int count{0};
    int tempCount{0};

    int temp{0};

    while (left < right)
    {
        count = 0;
        while (count < size - 1 - tempCount)
        {
            temp = matrix[top][left + count];
            matrix[top][left + count] = matrix[bottom - count][left];
            matrix[bottom - count][left] = matrix[bottom][right - count];
            matrix[bottom][right - count] = matrix[top + count][right];
            matrix[top + count][right] = temp;
        }
        tempCount += 2; //Think of it like we just finished the most outer square, so every time we finish it, we need to cut it by 2 to deal with inner square.
        top++;
        left++;
        bottom--;
        right--;
    }
}