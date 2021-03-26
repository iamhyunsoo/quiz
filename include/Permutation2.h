#include <algorithm>
#include <unordered_map>
#include <vector>

class Sol
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::vector<int> tmp;
        std::unordered_map<int, int> map;
        for (auto& x : nums)
        {
            ++map[x];
        }
        solve(map, tmp, nums.size());

        return ans;
    }
    void solve(std::unordered_map<int, int>& map, std::vector<int>& tmp, const int& size)
    {
        if (tmp.size() == (size_t)size)
        {
            ans.push_back(tmp);
            return;
        }

        for (auto& it : map)
        {
            if (!it.second)
                continue;

            tmp.push_back(it.first);
            --map[it.first];

            solve(map, tmp, size);
            
            tmp.pop_back();
            ++map[it.first];
        }
    }
private:
    std::vector<std::vector<int>> ans;
};

class Sol2
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::vector<int> initial = nums;
        do
        {
            ans.push_back(nums);
            nextPermutation(nums);

        } while (initial != nums);
        
        return ans;
    }
    void nextPermutation(std::vector<int>& nums)
    {
        int pos {0};

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pos = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= pos; i--)        //1 2 4 6 7 3
        {
            if (nums[pos] < nums[i])    
            {
                std::swap(nums[pos], nums[i]);
                pos++;
                break;
            }
        }
        std::reverse(nums.begin() + pos, nums.end());
    }
private:
    std::vector<std::vector<int>> ans;
};