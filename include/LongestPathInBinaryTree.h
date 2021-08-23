#include <algorithm>
#include <string>
#include <utility>
#include <vector>

int dfs(std::vector<std::pair<char, int>>& dict, int startIdx, int adjIdx)
{
    int len{ 0 };

    if (adjIdx != -1 && dict[startIdx].first == dict[adjIdx].first)
    {
        return len;
    }

    if (adjIdx != -1 && dict[startIdx].first != dict[adjIdx].first)
    {
        len++;
    }

    int MaxPathsFromThisPoint{ 0 };
    for (int i = startIdx + 1; i < static_cast<int>(dict.size()); i++)
    {
        if (dict[i].second == startIdx)
        {
            auto ret = dfs(dict, i, dict[i].second);
            if (adjIdx == -1)
            {
                len += ret;
            }
            else
            {
                MaxPathsFromThisPoint = std::max(MaxPathsFromThisPoint, ret);
            }
        }
    }
    return adjIdx == -1 ? len : len + MaxPathsFromThisPoint;
}

int solution(string& S, vector<int>& A)
{
    std::vector<std::pair<char, int>> dict;
    for (int i = 0; i < S.length(); i++)
    {
        dict.push_back({ S[i], A[i] });
    }
    std::sort(dict.begin(), dict.end(), [](std::pair<char,int> const& a, std::pair<char, int> const& b) {
        return a.second < b.second;
    });

    int longest{ 0 };

    for (int i = 0; i < static_cast<int>(S.length()); i++)
    {
        longest = std::max(longest, dfs(dict, i, -1));
    }
    return longest + 1;
}

/*
// Testcases..
int main()
{
    string str= "abab";
    vector<int> v = { -1,2,0,1 };
    std::cout << solution(str, v) << std::endl;

    string str2 = "abbab";
    vector<int> v2 = { -1,0,0,0,2 };
    std::cout << solution(str2, v2) << std::endl;

    string str3 = "ab";
    vector<int> v3 = { -1,0 };
    std::cout << solution(str3, v3) << std::endl;

    std::cout << "-------------------------------"<< std::endl;

    string str4 = "ababbba";
    vector<int> v4 = { -1,0,1,2,2,3,4 };
    std::cout << solution(str4, v4) << std::endl;

    string str5 = "abacbbcc";
    vector<int> v5 = { -1,0,0,2,3,3,4,5 };
    std::cout << solution(str5, v5) << std::endl;

    string str6 = "abaabbaaab";
    vector<int> v6 = { -1,0,1,1,2,3,4,5,6,7 };
    std::cout << solution(str6, v6) << std::endl;
}*/
