#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        const int len = s.length();
        if (len < 0)
        {
            return {};
        }
        int maxLen {0};                                                         //std::unordered_set could be used by 
        for (std::string& word : wordDict)                                      //transforming wordDict(std::vector) to
        {                                                                       //std::unordered_set for better performance
            maxLen = std::max( maxLen, static_cast<int>(word.length()) );       
        }

        std::unordered_map<int, std::vector<std::string>> map;
        return help(0, s, wordDict, map, maxLen);
    }

private:
    std::vector<std::string> 
    help
    (  
        const int& start, 
        const std::string& s, 
        const std::vector<std::string>& wordDict, 
        std::unordered_map<int, std::vector<std::string>> map,
        const int& maxLen
    ) 
    {
        if (map.count(start))
        {
            return map[start];
        }

        std::string tmp {};
        for (int i = start; i < s.length() && tmp.length() <= maxLen; i++)
        {
            tmp += s[i];
            if (std::find( wordDict.begin(), wordDict.end(), tmp ) != wordDict.end())
            {
                if (i == s.length() - 1)
                {
                    map[start].push_back(tmp);
                }
                else
                {
                    auto words = this->help(i + 1, s, wordDict, map, maxLen);
                    for (auto& word : words)
                    {
                        map[start].push_back(tmp + " " + word);
                    }
                }
            }
        }
        return map[start];
    }
};