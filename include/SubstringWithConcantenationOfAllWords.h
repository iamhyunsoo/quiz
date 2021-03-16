#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubString(std::string s, std::vector<std::string>& words)
{
    std::vector<int> ret;
    if (words.empty())
    {
        return ret;
    }
    int length = s.length();
    int wordSize = words[0].length();
    int size = words.size();

    std::unordered_map<std::string, int> map;

    for (const auto& x : words)
    {
        map[x]++;
    }

    for (int i = 0; i <= length - (wordSize * size); i++)
    {
        std::unordered_map<std::string, int> visited; 
        int j {0};
        for (; j < size; j++)
        {
            std::string sub = s.substr(i + (wordSize * j), wordSize);

            if (map.find(sub) != map.end())
            {
                visited[sub]++;

                if (visited[sub] > map[sub])
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        
        if (j == size)
        {
            ret.push_back(i);
        }
    }
    return ret;
}