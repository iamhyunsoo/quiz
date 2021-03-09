#include <algorithm>
#include <vector>

using namespace std;
class Solution1 {                                   //What I wanted at first
public:
    static vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  
            return total;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) 
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) 
                break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) 
                continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) 
                    continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) 
                    break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) 
                    continue;

                int left=j+1,right=n-1;
                while(left<right)
                {
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) 
                        left++;
                    else if(sum>target) 
                        right--;
                    else
                    {
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do
                        {
                            left++;
                        }while(nums[left]==nums[left-1]&&left<right);
                        do
                        {
                            right--;
                        }while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};


class Solution {                                          //What I did at first, and messed up.
public:
    std::vector< std::vector<int> > fourSum(std::vector<int>& nums, int target) 
    {
        int size = nums.size();
        if (size < 0)
        {
            return std::vector<std::vector<int>>();            
        }

        bool isZero = true;
        for (const int& x : nums)
        {
            if (x != 0)
            {
                isZero = false;
                break;
            }
        }
        
        if (target == 0 && isZero)
            return std::vector<std::vector< int > >{std::vector<int>{0,0,0,0}};

        std::vector< std::vector<int> > ret;
        
        std::sort(nums.begin(), nums.end());
        int l{0};
        int r{0};
        
        for (int i = 0; i < size - 3; ++i)
        {
            for (int j = i + 1; j < size-2; ++j)
            {
                l = j + 1;
                r = size - 1;
                
                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                    {
                        --r;                        
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                    {
                        ++l;                        
                    }
                    else
                    {
                        ret.emplace_back(std::vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        
                        while (nums[l] == nums[l - 1] && l < r)
                        {
                            ++l;
                        }
                    }
                }
                while (nums[j] == nums[j+1] && j < size-2)
                {
                    ++j;
                }
            }
            while(nums[i] == nums[i+1] && i < size - 3)
            {
                ++i;
            }
        }
        return ret;
    }
};

