#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int maxArea(vector<int>& height)
    {
       int left = 0; 
       int right = height.size() - 1;
       int area = 0; 
       
       while(left < right)
       {
           area = max(area, min(height[left],height[right])*(right-left));
           
           if(height[left] < height[right])
           {
               left++;
           }
           else
           {
               right--;
           }
       }
       return area;
    }
};