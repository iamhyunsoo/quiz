// Related Quizzes
// 668. Kth Smallest Number in Multiplication Table
// 719. Find K-th Smallest Pair Distance
// 786. K-th Smallest Prime Fraction


#include <algorithm>
#include <utility>
#include <vector>

// 378. Kth Smallest Element in a Sorted Matrix
class Solution 
{
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];

        while (l < r)
        {
            std::pair<int, int> beforeAfterofMid = { matrix[0][0], matrix[n - 1][n - 1] };
            int mid = l + (r - l) / 2;

            int cnt = HowManySmallerOrEqualMid(matrix, beforeAfterofMid, mid);

            if (cnt == k)
            {
                return beforeAfterofMid.first;
            }

            if (cnt < k)
            {
                l = beforeAfterofMid.second;
            }
            else
            {
                r = beforeAfterofMid.first;
            }
        }
        return l;
    }
private:
    int HowManySmallerOrEqualMid(std::vector<std::vector<int>>& matrix, std::pair<int, int>& beforeAfterMid, int mid)
    {
        int n = matrix.size();
        int r{ n - 1 };
        int c{ 0 };
        int cnt{ 0 };
        
        while (r >= 0 && c < n)
        {
            if (matrix[r][c] > mid)
            {
                beforeAfterMid.second = std::min(matrix[r][c], beforeAfterMid.second);
                r--;
            }
            else
            {
                beforeAfterMid.first = std::max(matrix[r][c], beforeAfterMid.first);
                cnt += (r + 1);
                c++;
            }
        }
        return cnt;
    }
};
