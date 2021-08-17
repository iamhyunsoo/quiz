#include <algorithm>
#include <string>
#include <vector>

std::string originalDigits(std::string s)
{
    std::vector<std::string> words = { "zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine" };
    std::vector<char> uniqueChar = { 'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i' };
    std::vector<int> nums = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
    std::vector<int> cnts(26, 0);
    std::string ret;

    for (auto c : s)
    {
        cnts[c - 'a']++;
    }

    for (int i = 0; i < 10; i++)
    {
        int cnt = cnts[uniqueChar[i] - 'a'];

        for (int j = 0; j < words[i].size(); j++)
        {
            cnts[words[i][j] - 'a'] -= cnt;
        }
        while (cnt--)
        {
            ret += std::to_string(nums[i]);
        }
    }

    std::sort(ret.begin(), ret.end());
    return ret;
}
