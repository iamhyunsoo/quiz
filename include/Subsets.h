#include <cmath>
#include <vector>

std::vector< std::vector<int> > subsets(std::vector<int>& nums)
{
    //Bit mask
    std::vector<std::vector<int>> ans;
    std::vector<int> tmp;
    ans.push_back(tmp);

    int size = nums.size();
    int curr {0};
    int n {0}; //temporary
    for (int i = 1; i < std::pow(2, size); i++)
    {
        tmp.clear();
        n = i;
        curr = size - 1;
        while (n != 0)
        {
            if (n & 1)
            {
                tmp.push_back(nums[curr]);
            }
            curr--;
            n >>= 1;
        }
        ans.push_back(tmp);
    }
    return ans;
}

class A
{
public:

    void help(int idx, const std::vector<int>& nums, std::vector<int>& tmp, const int& size)
    {
        ans.push_back(tmp);
        for (int i = idx; i < size; i++)
        {
            tmp.push_back(nums[i]);
            help(i + 1, nums, tmp, size);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets2(std::vector<int> &nums) //Backtracking
    {
        std::vector<int> tmp;
        help(0, nums, tmp, nums.size());
        return ans;        
    }

private:
    std::vector<std::vector<int>> ans;
};
