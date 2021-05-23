#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string largestNumber(vector<int>& nums)
{
    vector<string> vec;
    for (auto& num : nums)
    {
        vec.push_back(std::to_string(num));
    }

    std::sort(vec.begin(), vec.end(), [](std::string const& a, std::string const& b){
        return a+b > b+a;
    });

    std::string ans {};
    for (auto& num : vec)
    {
        ans += num;
    }

    while (ans[0] == '0' && ans.length() > 1)
    {
        ans.erase(0, 1);
    }
    return ans;
}