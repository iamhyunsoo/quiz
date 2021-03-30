#include <vector>

    std::vector<int> spiralOrder(std::vector< std::vector<int> >& matrix) 
    {
        std::vector<int> ans;
        int t = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() -1;
        int j {0};
        int news = 1;
        while (t <= b && l <= r)
        {
            if (news == 1)
            {
                for (j = l; j <= r; j++)
                {
                    ans.push_back(matrix[t][j]);
                }
                t++;
                news = 2;
            }
            else if (news == 2)
            {
                for (j = t; j <= b; j++)
                {
                    ans.push_back(matrix[j][r]);    
                }
                r--;
                news = 3;
            }
            else if (news == 3)
            {
                for (j = r; j >= l; j--)
                {
                    ans.push_back(matrix[b][j]);    
                }
                b--;  
                news = 4;
            }
            else if (news == 4)
            {
                for (j = b; j >= t; j--)
                {
                    ans.push_back(matrix[j][l]);    
                }
                l++;   
                news = 1;
            }
        }
        return ans;
    }