#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
    std::vector<std::string> ans;
    std::unordered_map<std::string, uint> map;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (map[s.substr(i,10)]++ == 1)             // Using hash function will make it faster apparently..
        {
            ans.push_back(s.substr(i, 10));
        }    
    }
    return ans;
}

#include <functional>
std::vector<std::string> findRepeatedDnaSequencesHash(std::string s)
{
    std::vector<std::string> ans;
    std::unordered_map<size_t, uint> map;
    std::hash<std::string> fn;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (map[fn(s.substr(i,10))]++ == 1)             // Using hash function will make it faster apparently..
        {
            ans.push_back(s.substr(i, 10));
        }    
    }
    return ans;
}