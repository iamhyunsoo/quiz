#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) //using sort
{
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (auto& s : strs)
    {
        std::string tmp(s);
        std::sort(tmp.begin(), tmp.end());
        map[tmp].push_back(s);        
    }
    std::vector<std::vector<std::string>> ans;
    for (auto& x : map)
    {
        ans.push_back(x.second);
    }
    return ans;
}

std::vector<std::vector<std::string>> groupAnagrams2(std::vector<std::string>& strs) //without sort
{
    std::map< std::map<char, int>, std::vector< std::string > > map;
    for (auto& s : strs)
    {
        std::map<char, int> tmp;
        for (auto& c : s)
        {
            tmp[c]++;
        }
        map[tmp].push_back(s);
    }
    std::vector<std::vector<std::string>> ans;
    for (auto& x : map)
    {
        ans.push_back(x.second);
    }
    return ans;
}