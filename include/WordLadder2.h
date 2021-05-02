#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    std::unordered_set< string > lists(wordList.begin(), wordList.end());
    vector< vector< string > > ans;
    queue< vector< string > > paths;
    vector<string> visited;
    int level = 1;

    paths.push({beginWord});

    while (!paths.empty())
    {
        vector<string> path = paths.front();
        paths.pop();

        if (path.size() > level)
        {
            for (auto& word : visited)
            {
                lists.erase(word);
            }
            visited.clear();
            level = path.size();
        }

        string last = path.back();
        for (int i = 0; i < last.length(); i++)
        {
            string word = last;
            for (char c = 'a'; c != 'z'; c++)
            {
                word[i] = c;
                if (lists.find(word) != lists.end())
                {
                    auto newPath = path;
                    newPath.push_back(word);
                    visited.push_back(word);
                    if (word == endWord)
                    {
                        ans.push_back(newPath);
                    }
                    else
                    {
                        paths.push(newPath);
                    }
                }
            }
        } 
    }
    return ans;
}
