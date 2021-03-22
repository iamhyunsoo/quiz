//Question: [1,1,2,3], 4

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    using It = std::vector<int>::iterator;

    vector< vector< int > > combinationSum2(vector<int>& candidates, int target)
    {   
        auto part= std::partition(candidates.begin(), candidates.end(), [=](auto x){ return x <= target;});
        std::sort(candidates.begin(), part);

        std::vector<int> tmp;
        solveRecursive(candidates.begin(), part, target, tmp);

        return answer;
    }

    void solveRecursive(It start, It end, int target, std::vector<int>& tmp)
    {
        if (start == end)
        {
            return;
        }

        int beg = *start;
        int remain = target - beg;
        if (remain < 0)
        {
            return;
        }
        else if (remain == 0)
        {
            tmp.push_back(beg);
            answer.push_back(tmp);
            tmp.pop_back();
        }
        else if (remain > 0)
        {
            tmp.push_back(beg);
            solveRecursive(++start, end, remain, tmp);
            tmp.pop_back();

            solveRecursive(std::upper_bound(start, end, beg), end, target, tmp);
        }

        return;
    }

private:
    vector< vector< int > > answer;
};