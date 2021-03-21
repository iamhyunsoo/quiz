#include <vector>

using namespace std;

class Solution
{
    public:
        void solve(std::vector<int>& candidates, int sum, int start, std::vector<int>& v)
        {
            if (sum < 0)
            {
                return;
            }
            else if (sum == 0)
            {
                answer.push_back(v);
                return;
            }

            for (int i = start; i < len; i++)
            {
                int tmp = candidates[i];
                v.push_back(tmp);
                solve(candidates, sum - tmp, i, v);
                v.pop_back();
            }
        }

        std::vector< std::vector< int > > combinationSum(std::vector<int>& candidates, int target)
        {
            len = candidates.size();
            std::vector<int> v;
            solve(candidates, target, 0, v);
            return answer;
        }

    private:
        std::vector< std::vector<int> > answer;
        size_t len;
};






































